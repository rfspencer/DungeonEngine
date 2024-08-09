// Copyright (c) 2024 Rich Spencer. All rights reserved.

#pragma once

#include <memory>
#include <vector>

template<typename T>
using UniquePtr = std::unique_ptr<T>;

template<typename T>
using SharedPtr = std::shared_ptr<T>;

template<typename T>
using WeakPtr = std::weak_ptr<T>;

template<typename T>
using List = std::vector<T>;
