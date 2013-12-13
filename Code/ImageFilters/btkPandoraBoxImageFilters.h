/*==========================================================================
  
  © Université de Strasbourg - Centre National de la Recherche Scientifique
  
  Date: 15/10/2013
  Author(s): François Rousseau
  
  This software is governed by the CeCILL-B license under French law and
  abiding by the rules of distribution of free software.  You can  use,
  modify and/ or redistribute the software under the terms of the CeCILL-B
  license as circulated by CEA, CNRS and INRIA at the following URL
  "http://www.cecill.info".
  
  As a counterpart to the access to the source code and  rights to copy,
  modify and redistribute granted by the license, users are provided only
  with a limited warranty  and the software's author,  the holder of the
  economic rights,  and the successive licensors  have only  limited
  liability.
  
  In this respect, the user's attention is drawn to the risks associated
  with loading,  using,  modifying and/or developing or reproducing the
  software by the user in light of its specific status of free software,
  that may mean  that it is complicated to manipulate,  and  that  also
  therefore means  that it is reserved for developers  and  experienced
  professionals having in-depth computer knowledge. Users are therefore
  encouraged to load and test the software's suitability as regards their
  requirements in conditions enabling the security of their systems and/or
  data to be ensured and,  more generally, to use and operate it in the
  same conditions as regards security.
  
  The fact that you are presently reading this means that you have had
  knowledge of the CeCILL-B license and that you accept its terms.
  
==========================================================================*/

#ifndef BTK_PANDORA_BOX_IMAGE_FILTERS_H
#define BTK_PANDORA_BOX_IMAGE_FILTERS_H

// STL includes
#include "vector"

// ITK includes
#include "itkImage.h"
#include "itkImageRegionIterator.h"

#include "itkDiscreteGaussianImageFilter.h"

namespace btk
{

class PandoraBoxImageFilters
{
    public:
    typedef itk::Image< short, 3>                              itkShortImage;
    typedef itkShortImage::Pointer                             itkShortImagePointer;
    typedef itk::ImageRegionIterator< itkShortImage >          itkShortIterator;

    typedef itk::Image< float, 3>                              itkFloatImage;
    typedef itkFloatImage::Pointer                             itkFloatImagePointer;
    typedef itk::ImageRegionIterator< itkFloatImage >          itkFloatIterator;

    typedef itk::DiscreteGaussianImageFilter< itkFloatImage,itkFloatImage > itkGaussianFilter;

    //Common filters on 3D float images --------------------------------------------------------------------------------
    static void DiscreteGaussianFiltering(itkFloatImagePointer & inputImage, itkFloatImagePointer & outputImage, float variance);

    //Methods on prabability images (stored as vector of images) -------------------------------------------------------
    static void ProbabilityImageNormalization(std::vector< itkFloatImagePointer > & inputImages, std::vector< itkFloatImagePointer > & outputImages);
    static void GetLabelWithMaxProbabilityImage(std::vector< itkFloatImagePointer > & inputImages, itkShortImagePointer & outputImage);

    //protected:

    //private:

};

} // namespace btk

#ifndef ITK_MANUAL_INSTANTIATION
#include "btkPandoraBoxImageFilters.txx"
#endif

#endif // BTK_PANDORA_BOX_IMAGE_FILTERS_H
