#ifndef Magnum_Trade_MiniExrImageConverter_h
#define Magnum_Trade_MiniExrImageConverter_h
/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015
              Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

/** @file
 * @brief Class @ref Magnum::Trade::MiniExrImageConverter
 */

#include <Magnum/Trade/AbstractImageConverter.h>

namespace Magnum { namespace Trade {

/**
@brief OpenEXR image converter plugin using miniexr

Supports images with format @ref PixelFormat::RGB or @ref PixelFormat::RGBA and
type @ref PixelType::HalfFloat. Does *not* support non-default
@ref PixelStorage::swapBytes() values.

This plugin is built if `WITH_MINIEXRIMAGECONVERTER` is enabled when building
Magnum Plugins. To use dynamic plugin, you need to load `MiniExrImageConverter`
plugin from `MAGNUM_PLUGINS_IMAGECONVERTER_DIR`. To use static plugin, you need
to request `MiniExrImageConverter` component of `MagnumPlugins` package in
CMake and link to `${MAGNUMPLUGINS_MINIEXRIMAGECONVERTER_LIBRARIES}`. To use
this as a dependency of another plugin, you additionally need to add
`${MAGNUMPLUGINS_MINIEXRIMAGECONVERTER_INCLUDE_DIRS}` to include path.

This plugins provides `OpenExrImageConverter` plugin, but note that this plugin
generates only uncompressed files and the performance might be worse than when
using plugin dedicated for given format.

See @ref building-plugins, @ref cmake-plugins and @ref plugins for more
information.
*/
class MiniExrImageConverter: public AbstractImageConverter {
    public:
        /** @brief Default constructor */
        explicit MiniExrImageConverter();

        /** @brief Plugin manager constructor */
        explicit MiniExrImageConverter(PluginManager::AbstractManager& manager, std::string plugin);

    private:
        Features doFeatures() const override;
        Containers::Array<char> doExportToData(const ImageView2D& image) override;
};

}}

#endif