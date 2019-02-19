//
// EPITECH PROJECT, 2019
// 4071.hpp
// File description:
// Sabri Ouaked 4071.hpp Include file
//
 
#include "IComponent.hpp"
#include "Gates.hpp"
#include "Pins.hpp"

class CMP4071: public nts::IComponent
{
	public:
		Pins **getPins() { return pins_array; }
		Gates **getGates() { return gates_array; }
		int countPins() { return _pins_nb; }
		int countGates() { return _gates_nb; }
		CMP4071(std::string name);
		std::string getName() { return _name; };
		void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
		nts::Tristate compute(std::size_t pin = 1);

	private:
		int _gates_nb;
		int _pins_nb;
		std::string _name;
		Pins *pins_array[12];
		Gates *gates_array[4];
};


nts::Tristate always_true(nts::Tristate *array)
{
 	return nts::Tristate::TRUE;
}

nts::Tristate CMP4071::compute(std::size_t pin)
{
	Pins *start = this->findPin(pin);;
	Pins *reference;
        bool ok = true;

        while (ok) {
                reference = start->getReference();
                if (reference->getGateId() > 0) {
	        	this->findGate(reference->getGateId())->compute();	
                } else {
                        if (!reference->getReference()) {
                                reference->getReference()->setState(reference->getState());                
                        } else {
                                ok = false;
                        }
                }

        }
	
	/*														
		get output -> check ref -> if on gates -> compute -> get output -> check ref -> if on gates -> compute 
								-> else setValue to next pin if out;
                																					 -> else setValue to next pin if out;
	*/
	
}

void CMP4071::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	Pins *currentcmp = this->findPin(pin);
	Pins *nextcmp = other.findPin(otherPin);

	/*	REFERENCE THE ERROR IN THE CORRECT CARD FOR TESTS	*/
	if (currentcmp->getRole() == ROLE::IN && nextcmp->getRole() == ROLE::IN) {
		perror("error:input:setLink:4071 Same pin types");
	} else if(currentcmp->getRole() == ROLE::OUT && nextcmp->getRole() == ROLE::OUT) {
		perror("error:output:setLink:4071 Same pin types");
	} else {
		currentcmp->setReference(nextcmp);
	}
}

CMP4071::CMP4071(std::string name)
{
	int id = 1;
	int i = 0;
	Pins *tmp_in;
	Pins *tmp_out;

	gates_array[0] = new Gates(2, 1, always_true, 1);
	gates_array[1] = new Gates(2, 1, always_true, 2);
	gates_array[2] = new Gates(2, 1, always_true, 3);
	gates_array[3] = new Gates(2, 1, always_true, 4);
	
	tmp_in = gates_array[0]->getInputs();
	tmp_out = gates_array[0]->getOuputs();
	
	pins_array[0] = new Pins(1, ROLE::OUT, &(tmp_in[1]));
	pins_array[1] = new Pins(2, ROLE::OUT, &(tmp_in[0]));
	pins_array[2] = new Pins(3, ROLE::IN, &(tmp_out[0]));

	tmp_in = gates_array[1]->getInputs();
	tmp_out = gates_array[1]->getOuputs();

	pins_array[3] = new Pins(4, ROLE::IN, &(tmp_out[0]));
	pins_array[4] = new Pins(5, ROLE::OUT, &(tmp_in[0]));
	pins_array[5] = new Pins(6, ROLE::OUT, &(tmp_in[1]));

	tmp_in = gates_array[2]->getInputs();
	tmp_out = gates_array[2]->getOuputs();

	pins_array[6] = new Pins(8, ROLE::OUT, &(tmp_in[0]));
	pins_array[7] = new Pins(9, ROLE::OUT, &(tmp_in[1]));
	pins_array[8] = new Pins(10, ROLE::IN, &(tmp_out[0]));

	tmp_in = gates_array[3]->getInputs();
	tmp_out = gates_array[3]->getOuputs();

	pins_array[9] = new Pins(11, ROLE::IN, &(tmp_out[0]));
	pins_array[10] = new Pins(12, ROLE::OUT, &(tmp_in[1]));
	pins_array[11] = new Pins(13, ROLE::OUT, &(tmp_in[0]));

	_name = name;
	_gates_nb = 4;
	_pins_nb = 12;
}