#pragma once
#include <iostream>
#include <vector>

using namespace std;

class clsString
{
private:
	string _Value = "";

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string Text)
	{
		return Text.length();
	};

	short Length()
	{
		return Length(_Value);
	};

	static short CountWords(string Text)
	{
		string delim = " "; // delimiter
		short Counter = 0;
		short pos = 0;
		string sWord; // define a string variable

		// use find() function to get the position of the delimiters
		while ((pos = Text.find(delim)) != std::string::npos)
		{
			sWord = Text.substr(0, pos); // store the word
			if (sWord != "")
			{
				Counter++;
			}

			//erase() until positon and move to next word.
			Text.erase(0, pos + delim.length());
		}
		if (Text != "")
		{
			Counter++; // it counts the last word of the string.
		}
		return Counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	};

	static string UpperFirstLetterOfEachWord(string Text)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ' && isFirstLetter)
			{
				Text[i] = toupper(Text[i]);
			}
			isFirstLetter = (Text[i] == ' ' ? true : false);
		}
		return Text;
	}

	void UpperFirstLetterOfEachWord()
	{
		// no need to return value , this procedure will directly update the object value  
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string Text)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < Text.length(); i++)
		{

			if (Text[i] != ' ' && isFirstLetter)
			{
				Text[i] = tolower(Text[i]);
			}
			isFirstLetter = (Text[i] == ' ' ? true : false);
		}
		return Text;
	}

	void LowerFirstLetterOfEachWord()
	{
		// no need to return value , this function will directly update the object value  
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = toupper(Text[i]);
		}
		return Text;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = tolower(Text[i]);
		}
		return Text;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static char InvertLetterCase(char Letter)
	{
		return isupper(Letter) ? tolower(Letter) : toupper(Letter);
	}

	static string InvertAllLettersCase(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = InvertLetterCase(Text[i]);
		}
		return Text;
	}

	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	static short CountLetters(string Text, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
		{
			return Text.length();
		}
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(Text[i]))
				Counter++;

			if (WhatToCount == enWhatToCount::SmallLetters && islower(Text[i]))
				Counter++;
		}
		return Counter;
	}

	static short CountCapitalLetters(string Text)
	{
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{
			if (isupper(Text[i]))
				Counter++;
		}
		return Counter;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string Text)
	{
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{
			if (islower(Text[i]))
				Counter++;
		}
		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountSpecificLetter(string Text, char Letter, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{
			if (MatchCase)
			{
				if (Text[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(Text[i]) == tolower(Letter))
					Counter++;
			}
		}
		return Counter;
	}

	short CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);
		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
	}

	static short CountVowels(string Text)
	{
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{
			if (IsVowel(Text[i]))
				Counter++;
		}
		return Counter;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static vector<string> Split(string Text, string Delim)
	{
		vector<string> vResults;
		short pos = 0;

		// use find() function to get the position of the delimiters  
		while ((pos = Text.find(Delim)) != std::string::npos)
		{
			if (pos != 0)
			{
				vResults.emplace_back(Text.substr(0, pos));
			}
			Text.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
		}

		if (Text != "")
		{
			vResults.push_back(Text); // it adds last word of the string.
		}

		return vResults;

	}

	vector<string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}

	static string TrimLeft(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ')
			{
				return Text.substr(i, Text.length() - i);
			}
		}
		return "";
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string Text)
	{
		for (short i = Text.length() - 1; i >= 0; i--)
		{
			if (Text[i] != ' ')
			{
				return Text.substr(0, i + 1);
			}
		}
		return "";
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string Text)
	{
		return (TrimLeft(TrimRight(Text)));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector<string> vString, string Delim)
	{
		string Text = "";

		for (string& S : vString)
		{
			Text = Text + S + Delim;
		}
		return Text.substr(0, Text.length() - Delim.length());
	}

	static string JoinString(string arrString[], short Length, string Delim)
	{
		string Text = "";

		for (short i = 0; i < Length; i++)
		{
			Text = Text + arrString[i] + Delim;
		}
		return Text.substr(0, Text.length() - Delim.length());
	}

	static string ReverseWordsInString(string Text)
	{
		vector<string> vString;
		string S2 = "";
		vString = Split(Text, " ");
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		S2 = S2.substr(0, S2.length() - 1); //remove last space.

		return S2;
	}

	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWord(string Text, string StringToReplace, string sRepalceTo, bool MatchCase = true)
	{
		vector<string> vString = Split(Text, " ");

		for (string& S : vString)
		{
			if (MatchCase)
			{
				if (S == StringToReplace)
				{
					S = sRepalceTo;
				}
			}
			else
			{
				if (LowerAllString(S) == LowerAllString(StringToReplace))
				{
					S = sRepalceTo;
				}
			}
		}
		return JoinString(vString, " ");
	}

	string ReplaceWord(string StringToReplace, string sRepalceTo)
	{
		return ReplaceWord(_Value, StringToReplace, sRepalceTo);
	}

	static string RemovePunctuations(string Text)
	{
		string S2 = "";

		for (short i = 0; i < Text.length(); i++)
		{
			if (!ispunct(Text[i]))
			{
				S2 += Text[i];
			}
		}
		return S2;
	}

	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}
};