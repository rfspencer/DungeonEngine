/**
* @file Types.h
 * @brief Header for the Types class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 *
 * This file contains templates for smart pointers
 */

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
