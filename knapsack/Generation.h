#pragma once
#include "Chromosome.h"

class Generation
{
public:
	int size;
	Chromosome *people;
	Generation(int size, int chromosomeSize) : size(size)
	{
		people = new Chromosome[size];
		for (int i = 0; i < size; i++)
		{
			people[i] = Chromosome(chromosomeSize);
		}
	}
	Generation(const Generation& other)
	{
		this->size = size;
		people = new Chromosome[size];
		for (int i = 0; i < size; i++)
		{
			people[i] = other.people[i];
		}
	}
	Generation& operator=(const Generation& other)
	{
		delete people;
		this->size = size;
		people = new Chromosome[size];
		for (int i = 0; i < size; i++)
		{
			people[i] = other.people[i];
		}

	}

	Chromosome& operator[](int index)
	{
		return people[index];
	}

	~Generation()
	{
		delete people;
	}


};

