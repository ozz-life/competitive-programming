#include <string>
#include <regex>

std::string DNAtoRNA(std::string dna){
  return dna = regex_replace(dna, std::regex("[T]"), "U");
}

///////////

std::string DNAtoRNA(std::string dna){
  std::replace(dna.begin(), dna.end(), 'T', 'U');
  return dna;
}

///////////

std::string DNAtoRNA(std::string dna)
{
  for(char &ch : dna)
  {
    if(ch == 'T')
    {
      ch = 'U';
    }
  }
  return dna;
}

///////////

std::string DNAtoRNA(std::string dna)
{
  for (int i = 0; i < dna.size(); i++)
  {
    if (dna[i] == 'T')
    {
      dna[i] = 'U';
    }
  }
  return dna;
}

////////////

std::string DNAtoRNA(std::string dna)
{  
  while(int i = dna.find('T')+1)
    dna.at(i-1) = 'U';
    
  return dna;
}