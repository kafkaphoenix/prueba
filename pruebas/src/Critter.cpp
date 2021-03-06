/*
 * critter.cpp
 *
 *  Created on: 10 may. 2017
 *      Author: sorak
 */

#include "Critter.h"
#include <stdexcept>
#include <iostream>

int Critter::s_Total=0;

int Critter::getTotal(){
	return s_Total;
}

void Critter::increaseTotal(){
	++s_Total;
}

void Critter::decreaseTotal(){
	--s_Total;
}

void Critter::greet()
{
	std::cout <<"Hola, tengo hambre: "<<m_Hunger<<std::endl;
}

void Critter::setHunger(int h){
	if(h<0){
		throw std::invalid_argument("N�mero negativo");
	}else{
		m_Hunger=h;
	}

}

int Critter::getHunger() const{
	return m_Hunger;
}

void Critter::setBoredom(int b){
	if(b<0){
		throw std::invalid_argument("N�mero negativo");
	}else{
		m_Boredom=b;
	}

}

int Critter::getBoredom() const{
	return m_Boredom;
}

Critter::Critter(){
	increaseTotal();
}

Critter::Critter(int x, int y, const std::string& name):m_Hunger(x),m_Boredom(y),m_Name(name){
	increaseTotal();
}

Critter::~Critter(){
	decreaseTotal();
}

std::string Critter::getName() const{
	return m_Name;
}

void peek(const Critter& aCritter){
	std::cout << aCritter.m_Name;
}
std::ostream& operator<<(std::ostream& os, const Critter& aCritter){
	os << "Critter Object - ";
	os << "m_Name: " << aCritter.m_Name;
	return os;
}

int* intOnHeap()
{
int* pTemp = new int(20);
return pTemp;
}
