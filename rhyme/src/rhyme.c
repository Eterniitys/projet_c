#include <stdio.h>
#include <stdlib.h>
String mots[3]={"fiskal","flat","SÂ°val"};
String [] rhyme(String [] mots, String mot1)
{
  for (int i = 0; i < sizeof(mots); i++)
  {
    String mot2=mots[i];
    /* code */
  }
  bool voyelle(char lettre)
  {
    char table[6]={"a","e","i","o","u","y"};
    for (int i = 0;i < sizeof(table);i++)
    {
      if (lettre==table[i])
        return true;
      else
        return false;
    }
  }

}
