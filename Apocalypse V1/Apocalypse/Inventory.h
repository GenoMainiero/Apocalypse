#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {

private:
	int food;
	int water;
	bool crowBar;
	bool electricalInsulatingGloves;
	bool flashLight;
	bool electricalTape;

public:
	int getFood() { return food; }
	void setFood(int foodVal) { food = foodVal; }

	int getWater() { return water; }
	void setWater(int waterVal) { water = waterVal; }

	bool getCrowBar() { return crowBar; }
	void setCrowBar(int crowBarVal) { crowBar = crowBarVal; }

	bool getElectricalInsulatingGloves() { return electricalInsulatingGloves; }
	void setElectricalInsulatingGloves(int electricalInsulatingGlovesVal) { electricalInsulatingGloves = electricalInsulatingGlovesVal; }

	bool getFlashLight() { return flashLight; }
	void setFlashLight(int flashLightVal) { flashLight = flashLightVal; }

	bool getElectricalTape() { return electricalTape; }
	void setElectricalTape(int electricalTapeVal) { electricalTape = electricalTapeVal; }
};

#endif
