#include <string>

class Matcher
{
	public:
		virtual bool matches(std::string character)
		{
			return false;
		}

		virtual bool isEpsilon()
		{
			return bool(0);
		}

		virtual std::string printLabel()
		{
			return "unidentified matcher";
		}

};

class CharacterMatcher: public Matcher
{
	public:
		std::string c;

		CharacterMatcher(std::string givenCharacter)
		{
			c = givenCharacter;
		}

		bool matches(std::string character) override
		{
			return (c == character);
		}

		bool isEpsilon() override
		{
			return false;
		}

		std::string printLabel() override
		{
			return c;
		}
};

class EpsilonMatcher: public Matcher
{
    public:
    	
    	bool matches(std::string character) override
    	{
    		return true;
    	}
                                                         
    	bool isEpsilon() override
    	{
    		return true;
    	}
                                                         
  	std::string printLabel() override
    	{
    		return "epsilon";
    	}
};
