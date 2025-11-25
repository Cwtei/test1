/*
 * PKW.h
 *
 *  Created on: Nov 4, 2025
 *      Author: cw
 */

#ifndef PKW_H_
#define PKW_H_

#include"Fahrzeug.h"

class PKW: public Fahrzeug
{
public:
	PKW(std::string sName, double dMaxGeschw, double dVerbrauch, double dTankvolumen = 55.0);
	virtual ~PKW();
	double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;
	void vAusgeben(std::ostream& out) const override;
	void vSimulieren() override;
	double dGeschwindigkeit() const override;
	void vZeichnen(const Weg& weg) const override;

	bool istBehindernd() const override;

private:
	double p_dVerbrauch; //Liter/100km
	double p_dTankvolumen; //Liter
	double p_dTankinhalt; //Liter
};

#endif /* PKW_H_ */
