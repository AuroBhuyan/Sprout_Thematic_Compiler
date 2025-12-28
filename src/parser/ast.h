#pragma once
#include <iostream>
#include <string>
#include <memory>

enum class TokenType
{
    Seed,
    Bloom,
    Identifier,
    Number,
    String,
    Equal,
    Unknown
};
