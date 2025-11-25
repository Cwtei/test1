/*
 * Kreuzung.h
 *
 *  Created on: Nov 25, 2025
 *      Author: cw
 */

#ifndef KREUZUNG_H_
#define KREUZUNG_H_

#include "Simulationsobjekt.h"
#include <list>

class Weg;
class Fahrzeug;
class Tempolimit;

class Kreuzung: public Simulationsobjekt {
public:
	Kreuzung();
	virtual ~Kreuzung();
	void vTanken(Fahrzeug& fahrzeug);
	void vAnnahme(std::unique_ptr<Fahrzeug>, double dStart);
	void vSimulieren() override;
	std::shared_ptr<Weg> pZufaelligerWeg(Weg& weg);

	double getTankstelle() const;

	static void vVerbinde(
			std::string sNameHin,
			std::string sNameRueck,
			double dLaenge,
			Tempolimit eTempolimit = Tempolimit::Autobahn,
			bool bUeberholverbot = true,
			std::shared_ptr<Kreuzung> pKreuzungStart = nullptr, //starting junction
			std::shared_ptr<Kreuzung> pKreuzungEnd = nullptr); //ending junction

	void addWeg(std::shared_ptr<Weg> pWeg);

private:
	std::list <std::shared_ptr<Weg>> p_pWege;//list of weg that connects to this kreuzung
	double p_dTankstelle; // volume of fuel available at this junction (litres)
};

#endif /* KREUZUNG_H_ */
