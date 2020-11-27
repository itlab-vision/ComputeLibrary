/*
 * Copyright (c) 2017-2020 Arm Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "arm_compute/runtime/GLES_COMPUTE/functions/GCFillBorder.h"

#include "arm_compute/core/GLES_COMPUTE/kernels/GCFillBorderKernel.h"
#include "arm_compute/core/Helpers.h"
#include "support/MemorySupport.h"

#include <utility>

using namespace arm_compute;

void GCFillBorder::configure(IGCTensor *tensor, unsigned int border_width, BorderMode border_mode, const PixelValue &constant_border_value)
{
    auto k = arm_compute::support::cpp14::make_unique<GCFillBorderKernel>();
    k->configure(tensor, BorderSize(border_width), border_mode, constant_border_value);
    _kernel = std::move(k);
}