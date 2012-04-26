/*
Copyright or © or Copr. Université de Strasbourg - Centre National de la Recherche Scientifique

14 april 2010
< pontabry at unistra dot fr >

This software is governed by the CeCILL-B license under French law and
abiding by the rules of distribution of free software. You can use,
modify and/ or redistribute the software under the terms of the CeCILL-B
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info".

As a counterpart to the access to the source code and rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty and the software's author, the holder of the
economic rights, and the successive licensors have only limited
liability.

In this respect, the user's attention is drawn to the risks associated
with loading, using, modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean that it is complicated to manipulate, and that also
therefore means that it is reserved for developers and experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or
data to be ensured and, more generally, to use and operate it in the
same conditions as regards security.

The fact that you are presently reading this means that you have had
knowledge of the CeCILL-B license and that you accept its terms.
*/

#include "btkDirection.h"


// Local includes
#include "btkCartesianCoordinates.h"


namespace btk
{

Direction::Direction() : SphericalCoordinates()
{
    // ----
}

Direction::Direction(Real azimuth, Real elevation) : SphericalCoordinates(azimuth, elevation, 1)
{
    // ----
}

Vector Direction::toVector()
{
    CartesianCoordinates c = this->toCartesianCoordinates();

    return Vector(c.x(), c.y(), c.z());
}

void Direction::setNull()
{
    m_theta = 0;
    m_phi   = 0;
    m_rho   = 0;
}

bool Direction::isNull()
{
    return (m_theta == 0) && (m_phi == 0) && (m_rho == 0);
}

std::ostream &operator<<(std::ostream &os, const Direction& u)
{
    return os << "(" << u.m_theta << ", " << u.m_phi << ")";
}

} // namespace btk

