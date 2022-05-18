// Copyright 2022 Hal@shurabaP.  All rights reserved.
// Use of this source code is governed by a MIT style
// license that can be found in the LICENSE file.

#include <iostream>
#include <data/Contour.hpp>

int main() {
    auto c = new uzume::vocoder::Contour(100.0, 2.0);
    std::cout << c->length;
    return 0;
}