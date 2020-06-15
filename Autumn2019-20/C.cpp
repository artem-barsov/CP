#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, string> kodon;
    kodon["UUU"] = "F";
    kodon["CUU"] = "L";
    kodon["AUU"] = "I";
    kodon["GUU"] = "V";
    kodon["UUC"] = "F";
    kodon["CUC"] = "L";
    kodon["AUC"] = "I";
    kodon["GUC"] = "V";
    kodon["UUA"] = "L";
    kodon["CUA"] = "L";
    kodon["AUA"] = "I";
    kodon["GUA"] = "V";
    kodon["UUG"] = "L";
    kodon["CUG"] = "L";
    kodon["AUG"] = "M";
    kodon["GUG"] = "V";
    kodon["UCU"] = "S";
    kodon["CCU"] = "P";
    kodon["ACU"] = "T";
    kodon["GCU"] = "A";
    kodon["UCC"] = "S";
    kodon["CCC"] = "P";
    kodon["ACC"] = "T";
    kodon["GCC"] = "A";
    kodon["UCA"] = "S";
    kodon["CCA"] = "P";
    kodon["ACA"] = "T";
    kodon["GCA"] = "A";
    kodon["UCG"] = "S";
    kodon["CCG"] = "P";
    kodon["ACG"] = "T";
    kodon["GCG"] = "A";
    kodon["UAU"] = "Y";
    kodon["CAU"] = "H";
    kodon["AAU"] = "N";
    kodon["GAU"] = "D";
    kodon["UAC"] = "Y";
    kodon["CAC"] = "H";
    kodon["AAC"] = "N";
    kodon["GAC"] = "D";
    kodon["UAA"] = "Stop";
    kodon["CAA"] = "Q";
    kodon["AAA"] = "K";
    kodon["GAA"] = "E";
    kodon["UAG"] = "Stop";
    kodon["CAG"] = "Q";
    kodon["AAG"] = "K";
    kodon["GAG"] = "E";
    kodon["UGU"] = "C";
    kodon["CGU"] = "R";
    kodon["AGU"] = "S";
    kodon["GGU"] = "G";
    kodon["UGC"] = "C";
    kodon["CGC"] = "R";
    kodon["AGC"] = "S";
    kodon["GGC"] = "G";
    kodon["UGA"] = "Stop";
    kodon["CGA"] = "R";
    kodon["AGA"] = "R";
    kodon["GGA"] = "G";
    kodon["UGG"] = "W";
    kodon["CGG"] = "R";
    kodon["AGG"] = "R";
    kodon["GGG"] = "G";
    string mrnk;
    cin >> mrnk;
    for (size_t i = 0; (kodon[mrnk.substr(i, 3)] != "Stop")&&(i < mrnk.length()); i += 3) {
// cout << i << ':' << i+3 << ' ' << mrnk.substr(i, 3) << ' ' << kodon[mrnk.substr(i, 3)] << '\n';
        cout << kodon[mrnk.substr(i, 3)];
    }
}
/*
UUU F      CUU L      AUU I      GUU V
UUC F      CUC L      AUC I      GUC V
UUA L      CUA L      AUA I      GUA V
UUG L      CUG L      AUG M      GUG V
UCU S      CCU P      ACU T      GCU A
UCC S      CCC P      ACC T      GCC A
UCA S      CCA P      ACA T      GCA A
UCG S      CCG P      ACG T      GCG A
UAU Y      CAU H      AAU N      GAU D
UAC Y      CAC H      AAC N      GAC D
UAA Stop   CAA Q      AAA K      GAA E
UAG Stop   CAG Q      AAG K      GAG E
UGU C      CGU R      AGU S      GGU G
UGC C      CGC R      AGC S      GGC G
UGA Stop   CGA R      AGA R      GGA G
UGG W      CGG R      AGG R      GGG G
*/
