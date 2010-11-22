/*
  Copyright 2010 SINTEF ICT, Applied Mathematics.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef OPM_BLACKOILPVT_HEADER_INCLUDED
#define OPM_BLACKOILPVT_HEADER_INCLUDED


#include "MiscibilityProps.hpp"
#include "BlackoilDefs.hpp"
#include <dune/common/EclipseGridParser.hpp>
#include <boost/scoped_ptr.hpp>
#include <string>


namespace Opm
{
    class BlackoilPVT : public BlackoilDefs
    {
    public:
	void init(const Dune::EclipseGridParser& ep);

        double getViscosity(double press,
                            const CompVec& surfvol,
			    PhaseIndex phase) const;
	CompVec surfaceDensities() const;
        double B   (double press,
                    const CompVec& surfvol,
		    PhaseIndex phase) const;
        double dBdp(double press,
                    const CompVec& surfvol,
		    PhaseIndex phase) const;
        double R   (double press,
                    const CompVec& surfvol,
		    PhaseIndex phase) const;
        double dRdp(double press,
                    const CompVec& surfvol,
		    PhaseIndex phase) const;


    private:
	int region_number_;
        const MiscibilityProps& propsForPhase(PhaseIndex phase) const;

	boost::scoped_ptr<MiscibilityProps> water_props_;
	boost::scoped_ptr<MiscibilityProps> oil_props_;
	boost::scoped_ptr<MiscibilityProps> gas_props_;
	CompVec densities_;
    };

}


#endif // OPM_BLACKOILPVT_HEADER_INCLUDED
