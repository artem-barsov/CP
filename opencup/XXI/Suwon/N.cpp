#include <iostream>
using namespace std;
int get(int x) {
    if (x >= 1 && x < 127) return 126;
    if (x >= 127 && x < 154) return 153;
    if (x >= 154 && x < 689) return 688;
    if (x >= 689 && x < 1207) return 1206;
    if (x >= 1207 && x < 1256) return 1255;
    if (x >= 1256 && x < 1261) return 1260;
    if (x >= 1261 && x < 1396) return 1395;
    if (x >= 1396 && x < 1436) return 1435;
    if (x >= 1436 && x < 1504) return 1503;
    if (x >= 1504 && x < 1531) return 1530;
    if (x >= 1531 && x < 1828) return 1827;
    if (x >= 1828 && x < 2188) return 2187;
    if (x >= 2188 && x < 3160) return 3159;
    if (x >= 3160 && x < 3785) return 3784;
    if (x >= 3785 && x < 6881) return 6880;
    if (x >= 6881 && x < 10252) return 10251;
    if (x >= 10252 && x < 10256) return 10255;
    if (x >= 10256 && x < 10427) return 10426;
    if (x >= 10427 && x < 10522) return 10521;
    if (x >= 10522 && x < 10526) return 10525;
    if (x >= 10526 && x < 10576) return 10575;
    if (x >= 10576 && x < 11260) return 11259;
    if (x >= 11260 && x < 11845) return 11844;
    if (x >= 11845 && x < 11849) return 11848;
    if (x >= 11849 && x < 12007) return 12006;
    if (x >= 12007 && x < 12061) return 12060;
    if (x >= 12061 && x < 12385) return 12384;
    if (x >= 12385 && x < 12506) return 12505;
    if (x >= 12506 && x < 12547) return 12546;
    if (x >= 12547 && x < 12551) return 12550;
    if (x >= 12551 && x < 12596) return 12595;
    if (x >= 12596 && x < 12601) return 12600;
    if (x >= 12601 && x < 12763) return 12762;
    if (x >= 12763 && x < 12844) return 12843;
    if (x >= 12844 && x < 12956) return 12955;
    if (x >= 12956 && x < 12965) return 12964;
    if (x >= 12965 && x < 13244) return 13243;
    if (x >= 13244 && x < 13546) return 13545;
    if (x >= 13546 && x < 13951) return 13950;
    if (x >= 13951 && x < 14036) return 14035;
    if (x >= 14036 && x < 14351) return 14350;
    if (x >= 14351 && x < 15004) return 15003;
    if (x >= 15004 && x < 15031) return 15030;
    if (x >= 15031 && x < 15247) return 15246;
    if (x >= 15247 && x < 15301) return 15300;
    if (x >= 15301 && x < 15436) return 15435;
    if (x >= 15436 && x < 15625) return 15624;
    if (x >= 15625 && x < 15796) return 15795;
    if (x >= 15796 && x < 16273) return 16272;
    if (x >= 16273 && x < 17326) return 17325;
    if (x >= 17326 && x < 17429) return 17428;
    if (x >= 17429 && x < 17438) return 17437;
    if (x >= 17438 && x < 17483) return 17482;
    if (x >= 17483 && x < 18226) return 18225;
    if (x >= 18226 && x < 18266) return 18265;
    if (x >= 18266 && x < 18271) return 18270;
    if (x >= 18271 && x < 19027) return 19026;
    if (x >= 19027 && x < 19216) return 19215;
    if (x >= 19216 && x < 21376) return 21375;
    if (x >= 21376 && x < 21587) return 21586;
    if (x >= 21587 && x < 21754) return 21753;
    if (x >= 21754 && x < 21871) return 21870;
    if (x >= 21871 && x < 25106) return 25105;
    if (x >= 25106 && x < 25376) return 25375;
    if (x >= 25376 && x < 25475) return 25474;
    if (x >= 25475 && x < 25511) return 25510;
    if (x >= 25511 && x < 28477) return 28476;
    if (x >= 28477 && x < 29633) return 29632;
    if (x >= 29633 && x < 31510) return 31509;
    if (x >= 31510 && x < 31591) return 31590;
    if (x >= 31591 && x < 33656) return 33655;
    if (x >= 33656 && x < 33697) return 33696;
    if (x >= 33697 && x < 36856) return 36855;
    if (x >= 36856 && x < 37841) return 37840;
    if (x >= 37841 && x < 37846) return 37845;
    if (x >= 37846 && x < 39785) return 39784;
    if (x >= 39785 && x < 41666) return 41665;
    if (x >= 41666 && x < 42899) return 42898;
    if (x >= 42899 && x < 44677) return 44676;
    if (x >= 44677 && x < 45685) return 45684;
    if (x >= 45685 && x < 45761) return 45760;
    if (x >= 45761 && x < 45865) return 45864;
    if (x >= 45865 && x < 47539) return 47538;
    if (x >= 47539 && x < 48673) return 48672;
    if (x >= 48673 && x < 49856) return 49855;
    if (x >= 49856 && x < 51760) return 51759;
    if (x >= 51760 && x < 52169) return 52168;
    if (x >= 52169 && x < 53866) return 53865;
    if (x >= 53866 && x < 56296) return 56295;
    if (x >= 56296 && x < 56876) return 56875;
    if (x >= 56876 && x < 62969) return 62968;
    if (x >= 62969 && x < 63896) return 63895;
    if (x >= 63896 && x < 67150) return 67149;
    if (x >= 67150 && x < 67393) return 67392;
    if (x >= 67393 && x < 67951) return 67950;
    if (x >= 67951 && x < 68801) return 68800;
    if (x >= 68801 && x < 71200) return 71199;
    if (x >= 71200 && x < 78976) return 78975;
    if (x >= 78976 && x < 100256) return 100255;
    if (x >= 100256 && x < 100526) return 100525;
    if (x >= 100526 && x < 101300) return 101299;
    if (x >= 101300 && x < 102052) return 102051;
    if (x >= 102052 && x < 102506) return 102505;
    if (x >= 102506 && x < 102511) return 102510;
    if (x >= 102511 && x < 102542) return 102541;
    if (x >= 102542 && x < 102551) return 102550;
    if (x >= 102551 && x < 102596) return 102595;
    if (x >= 102596 && x < 102943) return 102942;
    if (x >= 102943 && x < 102956) return 102955;
    if (x >= 102956 && x < 103969) return 103968;
    if (x >= 103969 && x < 104027) return 104026;
    if (x >= 104027 && x < 104261) return 104260;
    if (x >= 104261 && x < 104369) return 104368;
    if (x >= 104369 && x < 105022) return 105021;
    if (x >= 105022 && x < 105026) return 105025;
    if (x >= 105026 && x < 105076) return 105075;
    if (x >= 105076 && x < 105211) return 105210;
    if (x >= 105211 && x < 105251) return 105250;
    if (x >= 105251 && x < 105265) return 105264;
    if (x >= 105265 && x < 105296) return 105295;
    if (x >= 105296 && x < 105724) return 105723;
    if (x >= 105724 && x < 105751) return 105750;
    if (x >= 105751 && x < 107164) return 107163;
    if (x >= 107164 && x < 107330) return 107329;
    if (x >= 107330 && x < 108127) return 108126;
    if (x >= 108127 && x < 108136) return 108135;
    if (x >= 108136 && x < 108217) return 108216;
    if (x >= 108217 && x < 108613) return 108612;
    if (x >= 108613 && x < 108865) return 108864;
    if (x >= 108865 && x < 109526) return 109525;
    if (x >= 109526 && x < 110759) return 110758;
    if (x >= 110759 && x < 112469) return 112468;
    if (x >= 112469 && x < 112510) return 112509;
    if (x >= 112510 && x < 112591) return 112590;
    if (x >= 112591 && x < 114269) return 114268;
    if (x >= 114269 && x < 115673) return 115672;
    if (x >= 115673 && x < 115700) return 115699;
    if (x >= 115700 && x < 116479) return 116478;
    if (x >= 116479 && x < 116497) return 116496;
    if (x >= 116497 && x < 116726) return 116725;
    if (x >= 116726 && x < 116929) return 116928;
    if (x >= 116929 && x < 117068) return 117067;
    if (x >= 117068 && x < 118409) return 118408;
    if (x >= 118409 && x < 118441) return 118440;
    if (x >= 118441 && x < 118481) return 118480;
    if (x >= 118481 && x < 118576) return 118575;
    if (x >= 118576 && x < 118927) return 118926;
    if (x >= 118927 && x < 119849) return 119848;
    if (x >= 119849 && x < 120007) return 120006;
    if (x >= 120007 && x < 120061) return 120060;
    if (x >= 120061 && x < 120385) return 120384;
    if (x >= 120385 && x < 120601) return 120600;
    if (x >= 120601 && x < 120763) return 120762;
    if (x >= 120763 && x < 120844) return 120843;
    if (x >= 120844 && x < 121087) return 121086;
    if (x >= 121087 && x < 121577) return 121576;
    if (x >= 121577 && x < 121816) return 121815;
    if (x >= 121816 && x < 122747) return 122746;
    if (x >= 122747 && x < 122765) return 122764;
    if (x >= 122765 && x < 123085) return 123084;
    if (x >= 123085 && x < 123355) return 123354;
    if (x >= 123355 && x < 123539) return 123538;
    if (x >= 123539 && x < 123841) return 123840;
    if (x >= 123841 && x < 123895) return 123894;
    if (x >= 123895 && x < 124484) return 124483;
    if (x >= 124484 && x < 124489) return 124488;
    if (x >= 124489 && x < 124543) return 124542;
    if (x >= 124543 && x < 124979) return 124978;
    if (x >= 124979 && x < 125006) return 125005;
    if (x >= 125006 && x < 125051) return 125050;
    if (x >= 125051 && x < 125096) return 125095;
    if (x >= 125096 && x < 125249) return 125248;
    if (x >= 125249 && x < 125434) return 125433;
    if (x >= 125434 && x < 125461) return 125460;
    if (x >= 125461 && x < 125501) return 125500;
    if (x >= 125501 && x < 125951) return 125950;
    if (x >= 125951 && x < 125996) return 125995;
    if (x >= 125996 && x < 126001) return 126000;
    if (x >= 126001 && x < 126028) return 126027;
    if (x >= 126028 && x < 126109) return 126108;
    if (x >= 126109 && x < 126847) return 126846;
    if (x >= 126847 && x < 127418) return 127417;
    if (x >= 127418 && x < 127621) return 127620;
    if (x >= 127621 && x < 128404) return 128403;
    if (x >= 128404 && x < 128431) return 128430;
    if (x >= 128431 && x < 128944) return 128943;
    if (x >= 128944 && x < 129439) return 129438;
    if (x >= 129439 && x < 129506) return 129505;
    if (x >= 129506 && x < 129515) return 129514;
    if (x >= 129515 && x < 129551) return 129550;
    if (x >= 129551 && x < 129565) return 129564;
    if (x >= 129565 && x < 129596) return 129595;
    if (x >= 129596 && x < 129641) return 129640;
    if (x >= 129641 && x < 129776) return 129775;
    if (x >= 129776 && x < 129956) return 129955;
    if (x >= 129956 && x < 131243) return 131242;
    if (x >= 131243 && x < 132431) return 132430;
    if (x >= 132431 && x < 132566) return 132565;
    if (x >= 132566 && x < 132616) return 132615;
    if (x >= 132616 && x < 132656) return 132655;
    if (x >= 132656 && x < 133246) return 133245;
    if (x >= 133246 && x < 134276) return 134275;
    if (x >= 134276 && x < 134726) return 134725;
    if (x >= 134726 && x < 135046) return 135045;
    if (x >= 135046 && x < 135451) return 135450;
    if (x >= 135451 && x < 135829) return 135828;
    if (x >= 135829 && x < 135838) return 135837;
    if (x >= 135838 && x < 136526) return 136525;
    if (x >= 136526 && x < 136855) return 136854;
    if (x >= 136855 && x < 136949) return 136948;
    if (x >= 136949 && x < 138785) return 138784;
    if (x >= 138785 && x < 139501) return 139500;
    if (x >= 139501 && x < 139825) return 139824;
    if (x >= 139825 && x < 140036) return 140035;
    if (x >= 140036 && x < 140351) return 140350;
    if (x >= 140351 && x < 141346) return 141345;
    if (x >= 141346 && x < 142979) return 142978;
    if (x >= 142979 && x < 143501) return 143500;
    if (x >= 143501 && x < 143740) return 143739;
    if (x >= 143740 && x < 143794) return 143793;
    if (x >= 143794 && x < 145274) return 145273;
    if (x >= 145274 && x < 145315) return 145314;
    if (x >= 145315 && x < 145346) return 145345;
    if (x >= 145346 && x < 145684) return 145683;
    if (x >= 145684 && x < 146138) return 146137;
    if (x >= 146138 && x < 146521) return 146520;
    if (x >= 146521 && x < 146953) return 146952;
    if (x >= 146953 && x < 149365) return 149364;
    if (x >= 149365 && x < 149783) return 149782;
    if (x >= 149783 && x < 150004) return 150003;
    if (x >= 150004 && x < 150031) return 150030;
    if (x >= 150031 && x < 150247) return 150246;
    if (x >= 150247 && x < 150301) return 150300;
    if (x >= 150301 && x < 150436) return 150435;
    if (x >= 150436 && x < 150625) return 150624;
    if (x >= 150625 && x < 150827) return 150826;
    if (x >= 150827 && x < 152272) return 152271;
    if (x >= 152272 && x < 152407) return 152406;
    if (x >= 152407 && x < 152461) return 152460;
    if (x >= 152461 && x < 152609) return 152608;
    if (x >= 152609 && x < 152686) return 152685;
    if (x >= 152686 && x < 152947) return 152946;
    if (x >= 152947 && x < 153001) return 153000;
    if (x >= 153001 && x < 153437) return 153436;
    if (x >= 153437 && x < 154351) return 154350;
    if (x >= 154351 && x < 155278) return 155277;
    if (x >= 155278 && x < 156025) return 156024;
    if (x >= 156025 && x < 156241) return 156240;
    if (x >= 156241 && x < 156290) return 156289;
    if (x >= 156290 && x < 156326) return 156325;
    if (x >= 156326 && x < 156916) return 156915;
    if (x >= 156916 && x < 157951) return 157950;
    if (x >= 157951 && x < 158194) return 158193;
    if (x >= 158194 && x < 162073) return 162072;
    if (x >= 162073 && x < 162527) return 162526;
    if (x >= 162527 && x < 162721) return 162720;
    if (x >= 162721 && x < 162977) return 162976;
    if (x >= 162977 && x < 163256) return 163255;
    if (x >= 163256 && x < 163796) return 163795;
    if (x >= 163796 && x < 163855) return 163854;
    if (x >= 163855 && x < 163945) return 163944;
    if (x >= 163945 && x < 164584) return 164583;
    if (x >= 164584 && x < 165209) return 165208;
    if (x >= 165209 && x < 168521) return 168520;
    if (x >= 168521 && x < 171599) return 171598;
    if (x >= 171599 && x < 172247) return 172246;
    if (x >= 172247 && x < 172387) return 172386;
    if (x >= 172387 && x < 172823) return 172822;
    if (x >= 172823 && x < 173251) return 173250;
    if (x >= 173251 && x < 173926) return 173925;
    if (x >= 173926 && x < 174029) return 174028;
    if (x >= 174029 && x < 174083) return 174082;
    if (x >= 174083 && x < 174209) return 174208;
    if (x >= 174209 && x < 174281) return 174280;
    if (x >= 174281 && x < 174299) return 174298;
    if (x >= 174299 && x < 174371) return 174370;
    if (x >= 174371 && x < 174794) return 174793;
    if (x >= 174794 && x < 174803) return 174802;
    if (x >= 174803 && x < 174821) return 174820;
    if (x >= 174821 && x < 174983) return 174982;
    if (x >= 174983 && x < 175330) return 175329;
    if (x >= 175330 && x < 176216) return 176215;
    if (x >= 176216 && x < 178295) return 178294;
    if (x >= 178295 && x < 178943) return 178942;
    if (x >= 178943 && x < 179326) return 179325;
    if (x >= 179326 && x < 179429) return 179428;
    if (x >= 179429 && x < 179483) return 179482;
    if (x >= 179483 && x < 180226) return 180225;
    if (x >= 180226 && x < 180298) return 180297;
    if (x >= 180298 && x < 180622) return 180621;
    if (x >= 180622 && x < 182066) return 182065;
    if (x >= 182066 && x < 182251) return 182250;
    if (x >= 182251 && x < 182651) return 182650;
    if (x >= 182651 && x < 182701) return 182700;
    if (x >= 182701 && x < 182975) return 182974;
    if (x >= 182975 && x < 184127) return 184126;
    if (x >= 184127 && x < 186625) return 186624;
    if (x >= 186625 && x < 187030) return 187029;
    if (x >= 187030 && x < 189703) return 189702;
    if (x >= 189703 && x < 189743) return 189742;
    if (x >= 189743 && x < 190261) return 190260;
    if (x >= 190261 && x < 190828) return 190827;
    if (x >= 190828 && x < 191206) return 191205;
    if (x >= 191206 && x < 192151) return 192150;
    if (x >= 192151 && x < 192376) return 192375;
    if (x >= 192376 && x < 192686) return 192685;
    if (x >= 192686 && x < 192718) return 192717;
    if (x >= 192718 && x < 193258) return 193257;
    if (x >= 193258 && x < 193946) return 193945;
    if (x >= 193946 && x < 194230) return 194229;
    if (x >= 194230 && x < 197429) return 197428;
    if (x >= 197429 && x < 197483) return 197482;
    if (x >= 197483 && x < 197726) return 197725;
    if (x >= 197726 && x < 201853) return 201852;
    if (x >= 201853 && x < 205786) return 205785;
    if (x >= 205786 && x < 207392) return 207391;
    if (x >= 207392 && x < 208625) return 208624;
    if (x >= 208625 && x < 210376) return 210375;
    if (x >= 210376 && x < 210682) return 210681;
    if (x >= 210682 && x < 210754) return 210753;
    if (x >= 210754 && x < 211897) return 211896;
    if (x >= 211897 && x < 212869) return 212868;
    if (x >= 212869 && x < 213076) return 213075;
    if (x >= 213076 && x < 213467) return 213466;
    if (x >= 213467 && x < 213751) return 213750;
    if (x >= 213751 && x < 213760) return 213759;
    if (x >= 213760 && x < 214507) return 214506;
    if (x >= 214507 && x < 215087) return 215086;
    if (x >= 215087 && x < 215425) return 215424;
    if (x >= 215425 && x < 215456) return 215455;
    if (x >= 215456 && x < 215861) return 215860;
    if (x >= 215861 && x < 216734) return 216733;
    if (x >= 216734 && x < 217504) return 217503;
    if (x >= 217504 && x < 217531) return 217530;
    if (x >= 217531 && x < 217639) return 217638;
    if (x >= 217639 && x < 217855) return 217854;
    if (x >= 217855 && x < 218489) return 218488;
    if (x >= 218489 && x < 218701) return 218700;
    if (x >= 218701 && x < 223525) return 223524;
    if (x >= 223525 && x < 226499) return 226498;
    if (x >= 226499 && x < 226873) return 226872;
    if (x >= 226873 && x < 226877) return 226876;
    if (x >= 226877 && x < 227449) return 227448;
    if (x >= 227449 && x < 229649) return 229648;
    if (x >= 229649 && x < 231580) return 231579;
    if (x >= 231580 && x < 231674) return 231673;
    if (x >= 231674 && x < 233897) return 233896;
    if (x >= 233897 && x < 236755) return 236754;
    if (x >= 236755 && x < 236759) return 236758;
    if (x >= 236759 && x < 236926) return 236925;
    if (x >= 236926 && x < 238969) return 238968;
    if (x >= 238969 && x < 241507) return 241506;
    if (x >= 241507 && x < 241565) return 241564;
    if (x >= 241565 && x < 243176) return 243175;
    if (x >= 243176 && x < 245183) return 245182;
    if (x >= 245183 && x < 245449) return 245448;
    if (x >= 245449 && x < 246151) return 246150;
    if (x >= 246151 && x < 246929) return 246928;
    if (x >= 246929 && x < 250106) return 250105;
    if (x >= 250106 && x < 250511) return 250510;
    if (x >= 250511 && x < 251006) return 251005;
    if (x >= 251006 && x < 251051) return 251050;
    if (x >= 251051 && x < 251096) return 251095;
    if (x >= 251096 && x < 251897) return 251896;
    if (x >= 251897 && x < 253751) return 253750;
    if (x >= 253751 && x < 254741) return 254740;
    if (x >= 254741 && x < 255011) return 255010;
    if (x >= 255011 && x < 255101) return 255100;
    if (x >= 255101 && x < 256316) return 256315;
    if (x >= 256316 && x < 256411) return 256410;
    if (x >= 256411 && x < 256415) return 256414;
    if (x >= 256415 && x < 258796) return 258795;
    if (x >= 258796 && x < 259511) return 259510;
    if (x >= 259511 && x < 260339) return 260338;
    if (x >= 260339 && x < 261379) return 261378;
    if (x >= 261379 && x < 261784) return 261783;
    if (x >= 261784 && x < 262985) return 262984;
    if (x >= 262985 && x < 263075) return 263074;
    if (x >= 263075 && x < 263156) return 263155;
    if (x >= 263156 && x < 263737) return 263736;
    if (x >= 263737 && x < 267035) return 267034;
    if (x >= 267035 && x < 268399) return 268398;
    if (x >= 268399 && x < 279329) return 279328;
    if (x >= 279329 && x < 281737) return 281736;
    if (x >= 281737 && x < 283199) return 283198;
    if (x >= 283199 && x < 283649) return 283648;
    if (x >= 283649 && x < 284599) return 284598;
    if (x >= 284599 && x < 284761) return 284760;
    if (x >= 284761 && x < 285377) return 285376;
    if (x >= 285377 && x < 286417) return 286416;
    if (x >= 286417 && x < 286975) return 286974;
    if (x >= 286975 && x < 287357) return 287356;
    if (x >= 287357 && x < 289675) return 289674;
    if (x >= 289675 && x < 291376) return 291375;
    if (x >= 291376 && x < 291754) return 291753;
    if (x >= 291754 && x < 293626) return 293625;
    if (x >= 293626 && x < 295106) return 295105;
    if (x >= 295106 && x < 295511) return 295510;
    if (x >= 295511 && x < 296321) return 296320;
    if (x >= 296321 && x < 297464) return 297463;
    if (x >= 297464 && x < 297833) return 297832;
    if (x >= 297833 && x < 304718) return 304717;
    if (x >= 304718 && x < 307184) return 307183;
    if (x >= 307184 && x < 312476) return 312475;
    if (x >= 312476 && x < 312566) return 312565;
    if (x >= 312566 && x < 312656) return 312655;
    if (x >= 312656 && x < 312976) return 312975;
    if (x >= 312976 && x < 314200) return 314199;
    if (x >= 314200 && x < 314744) return 314743;
    if (x >= 314744 && x < 315010) return 315009;
    if (x >= 315010 && x < 315091) return 315090;
    if (x >= 315091 && x < 315491) return 315490;
    if (x >= 315491 && x < 315595) return 315594;
    if (x >= 315595 && x < 315626) return 315625;
    if (x >= 315626 && x < 315901) return 315900;
    if (x >= 315901 && x < 316256) return 316255;
    if (x >= 316256 && x < 319060) return 319059;
    if (x >= 319060 && x < 319537) return 319536;
    if (x >= 319537 && x < 325616) return 325615;
    if (x >= 325616 && x < 326156) return 326155;
    if (x >= 326156 && x < 326453) return 326452;
    if (x >= 326453 && x < 328420) return 328419;
    if (x >= 328420 && x < 328865) return 328864;
    if (x >= 328865 && x < 329347) return 329346;
    if (x >= 329347 && x < 329657) return 329656;
    if (x >= 329657 && x < 336196) return 336195;
    if (x >= 336196 && x < 336551) return 336550;
    if (x >= 336551 && x < 336961) return 336960;
    if (x >= 336961 && x < 338297) return 338296;
    if (x >= 338297 && x < 341285) return 341284;
    if (x >= 341285 && x < 341654) return 341653;
    if (x >= 341654 && x < 342689) return 342688;
    if (x >= 342689 && x < 346289) return 346288;
    if (x >= 346289 && x < 346726) return 346725;
    if (x >= 346726 && x < 346969) return 346968;
    if (x >= 346969 && x < 347914) return 347913;
    if (x >= 347914 && x < 352967) return 352966;
    if (x >= 352967 && x < 355996) return 355995;
    if (x >= 355996 && x < 361990) return 361989;
    if (x >= 361990 && x < 362993) return 362992;
    if (x >= 362993 && x < 365639) return 365638;
    if (x >= 365639 && x < 368105) return 368104;
    if (x >= 368105 && x < 368551) return 368550;
    if (x >= 368551 && x < 368785) return 368784;
    if (x >= 368785 && x < 369190) return 369189;
    if (x >= 369190 && x < 371894) return 371893;
    if (x >= 371894 && x < 373865) return 373864;
    if (x >= 373865 && x < 375157) return 375156;
    if (x >= 375157 && x < 375616) return 375615;
    if (x >= 375616 && x < 376993) return 376992;
    if (x >= 376993 && x < 378401) return 378400;
    if (x >= 378401 && x < 378419) return 378418;
    if (x >= 378419 && x < 378451) return 378450;
    if (x >= 378451 && x < 381430) return 381429;
    if (x >= 381430 && x < 384913) return 384912;
    if (x >= 384913 && x < 384926) return 384925;
    if (x >= 384926 && x < 386416) return 386415;
    if (x >= 386416 && x < 390848) return 390847;
    if (x >= 390848 && x < 392567) return 392566;
    if (x >= 392567 && x < 393247) return 393246;
    if (x >= 393247 && x < 393418) return 393417;
    if (x >= 393418 && x < 394876) return 394875;
    if (x >= 394876 && x < 397841) return 397840;
    if (x >= 397841 && x < 399785) return 399784;
    if (x >= 399785 && x < 404933) return 404932;
    if (x >= 404933 && x < 404969) return 404968;
    if (x >= 404969 && x < 414896) return 414895;
    if (x >= 414896 && x < 415576) return 415575;
    if (x >= 415576 && x < 416066) return 416065;
    if (x >= 416066 && x < 416260) return 416259;
    if (x >= 416260 && x < 416651) return 416650;
    if (x >= 416651 && x < 416989) return 416988;
    if (x >= 416989 && x < 419288) return 419287;
    if (x >= 419288 && x < 428981) return 428980;
    if (x >= 428981 && x < 429665) return 429664;
    if (x >= 429665 && x < 435785) return 435784;
    if (x >= 435785 && x < 439583) return 439582;
    if (x >= 439583 && x < 442976) return 442975;
    if (x >= 442976 && x < 446761) return 446760;
    if (x >= 446761 && x < 446977) return 446976;
    if (x >= 446977 && x < 447917) return 447916;
    if (x >= 447917 && x < 449677) return 449676;
    if (x >= 449677 && x < 449956) return 449955;
    if (x >= 449956 && x < 450689) return 450688;
    if (x >= 450689 && x < 451769) return 451768;
    if (x >= 451769 && x < 456841) return 456840;
    if (x >= 456841 && x < 457169) return 457168;
    if (x >= 457169 && x < 457601) return 457600;
    if (x >= 457601 && x < 458641) return 458640;
    if (x >= 458641 && x < 462673) return 462672;
    if (x >= 462673 && x < 465089) return 465088;
    if (x >= 465089 && x < 465985) return 465984;
    if (x >= 465985 && x < 468536) return 468535;
    if (x >= 468536 && x < 475381) return 475380;
    if (x >= 475381 && x < 475894) return 475893;
    if (x >= 475894 && x < 476893) return 476892;
    if (x >= 476893 && x < 486721) return 486720;
    if (x >= 486721 && x < 488593) return 488592;
    if (x >= 488593 && x < 489160) return 489159;
    if (x >= 489160 && x < 489956) return 489955;
    if (x >= 489956 && x < 490177) return 490176;
    if (x >= 490177 && x < 491689) return 491688;
    if (x >= 491689 && x < 493858) return 493857;
    if (x >= 493858 && x < 495329) return 495328;
    if (x >= 495329 && x < 497683) return 497682;
    if (x >= 497683 && x < 498551) return 498550;
    if (x >= 498551 && x < 515908) return 515907;
    if (x >= 515908 && x < 516880) return 516879;
    if (x >= 516880 && x < 517510) return 517509;
    if (x >= 517510 && x < 517591) return 517590;
    if (x >= 517591 && x < 519746) return 519745;
    if (x >= 519746 && x < 520169) return 520168;
    if (x >= 520169 && x < 520817) return 520816;
    if (x >= 520817 && x < 521609) return 521608;
    if (x >= 521609 && x < 521681) return 521680;
    if (x >= 521681 && x < 526793) return 526792;
    if (x >= 526793 && x < 529673) return 529672;
    if (x >= 529673 && x < 530380) return 530379;
    if (x >= 530380 && x < 531298) return 531297;
    if (x >= 531298 && x < 535969) return 535968;
    if (x >= 535969 && x < 536540) return 536539;
    if (x >= 536540 && x < 538651) return 538650;
    if (x >= 538651 && x < 549766) return 549765;
    if (x >= 549766 && x < 559189) return 559188;
    if (x >= 559189 && x < 562951) return 562950;
    if (x >= 562951 && x < 564913) return 564912;
    if (x >= 564913 && x < 567649) return 567648;
    if (x >= 567649 && x < 568751) return 568750;
    if (x >= 568751 && x < 571649) return 571648;
    if (x >= 571649 && x < 573769) return 573768;
    if (x >= 573769 && x < 588677) return 588676;
    if (x >= 588677 && x < 611794) return 611793;
    if (x >= 611794 && x < 611879) return 611878;
    if (x >= 611879 && x < 612599) return 612598;
    if (x >= 612599 && x < 614966) return 614965;
    if (x >= 614966 && x < 617729) return 617728;
    if (x >= 617729 && x < 618760) return 618759;
    if (x >= 618760 && x < 623759) return 623758;
    if (x >= 623759 && x < 629681) return 629680;
    if (x >= 629681 && x < 632876) return 632875;
    if (x >= 632876 && x < 638951) return 638950;
    if (x >= 638951 && x < 649639) return 649638;
    if (x >= 649639 && x < 661289) return 661288;
    if (x >= 661289 && x < 665920) return 665919;
    if (x >= 665920 && x < 667877) return 667876;
    if (x >= 667877 && x < 671410) return 671409;
    if (x >= 671410 && x < 671491) return 671490;
    if (x >= 671491 && x < 671945) return 671944;
    if (x >= 671945 && x < 673921) return 673920;
    if (x >= 673921 && x < 678893) return 678892;
    if (x >= 678893 && x < 679501) return 679500;
    if (x >= 679501 && x < 687920) return 687919;
    if (x >= 687920 && x < 688001) return 688000;
    if (x >= 688001 && x < 692713) return 692712;
    if (x >= 692713 && x < 697249) return 697248;
    if (x >= 697249 && x < 702190) return 702189;
    if (x >= 702190 && x < 702919) return 702918;
    if (x >= 702919 && x < 710497) return 710496;
    if (x >= 710497 && x < 711100) return 711099;
    if (x >= 711100 && x < 711910) return 711909;
    if (x >= 711910 && x < 711991) return 711990;
    if (x >= 711991 && x < 715960) return 715959;
    if (x >= 715960 && x < 719200) return 719199;
    if (x >= 719200 && x < 729689) return 729688;
    if (x >= 729689 && x < 736696) return 736695;
    if (x >= 736696 && x < 738469) return 738468;
    if (x >= 738469 && x < 741929) return 741928;
    if (x >= 741929 && x < 769793) return 769792;
    if (x >= 769793 && x < 773897) return 773896;
    if (x >= 773897 && x < 778937) return 778936;
    if (x >= 778937 && x < 782897) return 782896;
    if (x >= 782897 && x < 785296) return 785295;
    if (x >= 785296 && x < 789251) return 789250;
    if (x >= 789251 && x < 789526) return 789525;
    if (x >= 789526 && x < 789751) return 789750;
    if (x >= 789751 && x < 791290) return 791289;
    if (x >= 791290 && x < 792586) return 792585;
    if (x >= 792586 && x < 794089) return 794088;
    if (x >= 794089 && x < 798683) return 798682;
    if (x >= 798683 && x < 809920) return 809919;
    if (x >= 809920 && x < 809938) return 809937;
    if (x >= 809938 && x < 809965) return 809964;
    if (x >= 809965 && x < 815959) return 815958;
    if (x >= 815959 && x < 829697) return 829696;
    if (x >= 829697 && x < 841996) return 841995;
    if (x >= 841996 && x < 859969) return 859968;
    if (x >= 859969 && x < 899020) return 899019;
    if (x >= 899020 && x < 936986) return 936985;
    if (x >= 936986 && x < 939659) return 939658;
    if (x >= 939659 && x < 960989) return 960988;
    if (x >= 960988 && x <= 1000000) return 1000255;
}

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        cout << get(n) << '\n';
        cin >> n;
    }
}