/*
 * Fahrrad.h
 *
 *  Created on: Nov 4, 2025
 *      Author: cw
 */

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

#include"Fahrzeug.h"

class Fahrrad: public Fahrzeug
{
public:
	Fahrrad(std::string sName, double dMaxGeschw);
	double dGeschwindigkeit() const override;
	virtual ~Fahrrad();
	void vZeichnen(const Weg& weg) const override;
	bool istBehindernd() const override;
};

#endif /* FAHRRAD_H_ */
