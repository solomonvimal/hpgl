#include "stdafx.h"
#include "calc_mean.h"
#include "property_array.h"


	double hpgl::calc_mean(const cont_property_array_t & property, bool * success)
	{	
		int count_points = 0;
		double sum = 0;

		// Mean computation procedure
		for(int idx = 0; idx < property.size(); ++idx)
		{
			if( property.is_informed(idx) )
			{
				sum += property.get_at(idx);
				count_points += 1;
			}
		}		
		if (count_points == 0)
		{
			*success = false;
			return 0;
		}
		else
		{
			*success = true;
			return sum / count_points;
		}
	}

namespace hpgl
{

	bool calc_mean(const cont_property_array_t * property, double * mean)
	{		
		if (!property || ! mean)
			return false;

		int count_points = 0;
		double sum = 0;
		// Mean computation procedure
		for(int idx = 0; idx < property->size(); ++idx)
		{
			if( property->is_informed(idx) )
			{
				sum += property->get_at(idx);
				count_points += 1;
			}
		}		
		*mean = sum / count_points;		
		return true;
	}
}