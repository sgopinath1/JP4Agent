//
// Juniper P4 compiler 
//
/// @file  backend.cpp
/// @brief P4 compiler for Juniper AFI
//
// Created by Sandesh Kumar Sodhi, December, 2017
// Copyright (c) [2017] Juniper Networks, Inc. All rights reserved.
//
// All rights reserved.
//
// Notice and Disclaimer: This code is licensed to you under the Apache
// License 2.0 (the "License"). You may not use this code except in compliance
// with the License. This code is not an official Juniper product. You can
// obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
//
// Third-Party Code: This code may depend on other components under separate
// copyright notice and license terms. Your use of the source code for those
// components is subject to the terms and conditions of the respective license
// as noted in the Third-Party source code file.
//

#ifndef _BACKENDS_AFI_HELPERS_H_
#define _BACKENDS_AFI_HELPERS_H_

#include "ir/ir.h"
#include "lib/cstring.h"
#include "lib/json.h"
#include "lib/ordered_map.h"
#include "analyzer.h"
#include "frontends/common/model.h"

namespace AFI {

/// constant used in backend code generation
class TableImplementation {
 public:
    static const cstring actionProfileName;
    static const cstring actionSelectorName;
    static const cstring directCounterName;
    static const cstring directMeterName;
    static const cstring counterName;
};

class MatchImplementation {
 public:
    static const cstring selectorMatchTypeName;
    static const cstring rangeMatchTypeName;
};

class TableAttributes {
 public:
    static const cstring implementationName;
    static const cstring sizeName;
    static const cstring supportTimeoutName;
    static const unsigned defaultTableSize;
    static const cstring countersName;
    static const cstring metersName;
};

class V1ModelProperties {
 public:
    static const cstring jsonMetadataParameterName;

    /// The name of AFI's valid field. This is a hidden bit<1> field
    /// automatically added by AFI to all header types; reading from it tells
    /// you whether the header is valid, just as if you had called isValid().
    static const cstring validField;
};

using ErrorValue = unsigned int;
using ErrorCodesMap = ordered_map<const IR::IDeclaration *, ErrorValue>;
using BlockTypeMap = std::map<const IR::Block*, const IR::Type*>;

Util::IJson* nodeName(const CFG::Node* node);
Util::JsonArray* mkArrayField(Util::JsonObject* parent, cstring name);
Util::JsonArray* mkParameters(Util::JsonObject* object);
Util::JsonArray* pushNewArray(Util::JsonArray* parent);
Util::JsonObject* mkPrimitive(cstring name, Util::JsonArray* appendTo);
cstring stringRepr(mpz_class value, unsigned bytes = 0);
unsigned nextId(cstring group);

}  // namespace AFI

#endif /* _BACKENDS_AFI_HELPERS_H_ */
