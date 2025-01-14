#include <stdbool.h>
#include <string.h>

bool isAnagram(char *s, char *t)
{
    if (strlen(s) != strlen(t))
        return false;
    int s_count[26] = {0}, t_count[26] = {0};
    for (int i = 0; i < strlen(s); i++)
    {
        s_count[s[i] - 'a']++;
        t_count[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (s_count[i] != t_count[i])
            return false;
    }
    return true;
}