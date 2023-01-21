#pragma once
#include "BaseConverter.h"

class LouderConverter : BaseConverter {
	LouderConverter(Interval interval) : BaseConverter(interval) {}

	virtual Chunk process(const Context& context);
};
