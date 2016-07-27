//preconditions: none
//postconditions: none
//description: generates a hash based on inputInteger and returns it in O(1) time
size_t musla::hashInteger(uint32_t inputInteger, size_t modulus) const
{
	//h(k) = k(k+3) mod m from https://www.cs.hmc.edu/~geoff/classes/hmc.cs070.200101/homework10/hashfuncs.html
	uint64_t hashVal = inputInteger * (inputInteger + 3);
	hashVal %= modulus;
	
	return (size_t)hashVal;
}

//preconditions: none
//postconditions: none
//description: generates a hash based on inputInteger and returns it in O(1) time
size_t musla::hashString(std::string inputString, size_t modulus) const
{
	uint64_t hashVal = 0;
	
	size_t index = 0;
	while(inputString[index] != '\0')
	{
		hashVal += (index + 1) * inputString[index];
	}
	
	hashVal %= modulus; //shrink to new range
	
	return (size_t)hashVal;
}

size_t musla::hashString2(std::string inputString, size_t modulus) const
{
	uint64_t hashVal = 5381;
	int c;
	for(int i = 0; i < inputString.length(); ++i)
	{
		c = (int) inputString[i];
		hashVal = ((hashVal << 5) + hashVal) + c;
	}
	return (size_t)hashVal;
}
