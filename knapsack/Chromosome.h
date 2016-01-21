#pragma once
#include <iostream>
#include <cstdlib>

class Chromosome
{
public:
	int size;
	bool *genes;
	Chromosome(int size = 0) : size(size)
	{
		genes = new bool[size];
		for (int i = 0; i < size; i++)
		{
			genes[i] = (bool)(rand() % 2);
		}
	}
	Chromosome(const Chromosome& other)
	{
		this->size = size;
		genes = new bool[size];
		for (int i = 0; i < size; i++)
		{
			genes[i] = other.genes[i];
		}
	}
	Chromosome& operator=(const Chromosome& other)
	{
		if (this != &other)
		{
			delete genes;
			this->size = size;
			genes = new bool[size];
			for (int i = 0; i < size; i++)
			{
				genes[i] = other.genes[i];
			}
		}
	}

	bool& operator[](int index)
	{
		return genes[index];
	}

	void crossover(Chromosome& other)
	{
		if (rand() % 10 < 7) // about 0.7 rate
		{
			bool temp;
			int crossoverPoint = rand() % size;
			for (int i = 0; i < crossoverPoint; i++)
			{
				temp = genes[i];
				genes[i] = other.genes[i];
				other.genes[i] = temp;
			}
		}
	}

	void mutate()
	{
		for (int i = 0; i < size; i++)
		{
			if (rand() % 10000 < 10) // about 0.001 rate
			{
				genes[i] = !genes[i];
			}
		}
	}
	
	int calcFitness(int *itemsValue, int *itemsVolume, int maxVolume)
	{
		int totalValue = 0, totalVolume = 0;
		for (int i = 0; i < size; i++)
		{
			totalValue += itemsValue[i] * genes[i];
			totalVolume += itemsVolume[i] * genes[i];
		}
		if (totalVolume <= maxVolume)
		{
			return totalValue;
		}
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << genes[i];
		}
		std::cout << std::endl;
	}

	~Chromosome()
	{
		delete genes;
	}
};


