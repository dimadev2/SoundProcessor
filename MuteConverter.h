#pragma once
#include "BaseConverter.h"

class MuteConverter : BaseConverter {
	MuteConverter(Interval interval) : BaseConverter(interval) {}

	virtual Chunk process(const Context& context);
};
