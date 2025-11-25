/*
 * Simulationsobjekt.cpp
 *
 *  Created on: Nov 9, 2025
 *      Author: cw
 */

#include "Simulationsobjekt.h"
#include <string>
#include <iomanip>
#include <iostream>

Simulationsobjekt::Simulationsobjekt() : p_dZeit(0.0), p_sName(""), p_iID(++p_iMaxID)
{}

Simulationsobjekt::Simulationsobjekt(std::string sName) : p_dZeit(0.0), p_sName(sName), p_iID(++p_iMaxID)
{}

Simulationsobjekt::~Simulationsobjekt()
{
	std::cout  << "Destruktor: Simulationsobjekt " << p_iID << "(" << p_sName << ") wurde geloescht." << std::endl;
}

void Simulationsobjekt::vAusgeben(std::ostream& out) const
{
	out << std::resetiosflags(std::ios::right)
			<< std::setiosflags(std::ios::left)
			<< std::setw(3) << p_iID << "   "
			<< std::setw(5) << p_sName ;
}

std::ostream& operator << (std::ostream& out, const Simulationsobjekt& simulationsobjekt)
{
	simulationsobjekt.vAusgeben(out);
	return out;
}

bool Simulationsobjekt::operator == (const Simulationsobjekt& simulationsobjekt) const
{
	return (this->p_iID == simulationsobjekt.p_iID);
}

std::string Simulationsobjekt::getName() const
{
	return p_sName;
}
