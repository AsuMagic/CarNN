#pragma once

#include "network.hpp"

struct Individual
{
	std::size_t car_id = 0;

	Network network;

	bool   survivor_from_last = false;
	double last_fitness       = 0.0;

	template<class Archive>
	void serialize(Archive& ar)
	{
		ar(network, survivor_from_last, last_fitness);
	}
};
