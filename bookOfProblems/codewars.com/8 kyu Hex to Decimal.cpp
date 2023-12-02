int hexToDec(std::string hexString)
{
    return stoi(hexString, 0, 16);
}

///////////


int hexToDec(const std::string& hexString)
{
    return std::stoi(hexString, nullptr, 16);
}

//////////

