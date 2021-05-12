from datetime import datetime

date_time_str = input()
date_time_obj = datetime.strptime(date_time_str, '%Y-%m-%d')
date_aries       = (datetime(month=3, day=21, year = date_time_obj.year), datetime(month=4, day=19, year = date_time_obj.year))
date_taurus      = (datetime(month=4, day=20, year = date_time_obj.year), datetime(month=5, day=20, year = date_time_obj.year))
date_gemini      = (datetime(month=5, day=21, year = date_time_obj.year), datetime(month=6, day=20, year = date_time_obj.year))
date_cancer      = (datetime(month=6, day=21, year = date_time_obj.year), datetime(month=7, day=22, year = date_time_obj.year))
date_leo         = (datetime(month=7, day=23, year = date_time_obj.year), datetime(month=8, day=22, year = date_time_obj.year))
date_virgo       = (datetime(month=8, day=23, year = date_time_obj.year), datetime(month=9, day=22, year = date_time_obj.year))
date_libra       = (datetime(month=9, day=23, year = date_time_obj.year), datetime(month=10, day=22, year = date_time_obj.year))
date_scorpio     = (datetime(month=10, day=23, year = date_time_obj.year),datetime(month=11, day=22, year = date_time_obj.year))
date_saggitarius = (datetime(month=11, day=23, year = date_time_obj.year),datetime(month=12, day=21, year = date_time_obj.year))
date_capricorn   = (datetime(month=12, day=22, year = date_time_obj.year),datetime(month=1, day=19, year = date_time_obj.year))
date_aquarius    = (datetime(month=1, day=20, year = date_time_obj.year), datetime(month=2, day=18, year = date_time_obj.year))
date_pisces      = (datetime(month=2, day=19, year = date_time_obj.year), datetime(month=3, day=20, year = date_time_obj.year))

if(date_aries[0] <= date_time_obj <= date_aries[1]):
    print("Aries")
elif(date_taurus[0] <= date_time_obj <= date_taurus[1]):
    print("Taurus")
elif(date_gemini[0] <= date_time_obj <= date_gemini[1]):
    print("Gemini")
elif(date_cancer[0] <= date_time_obj <= date_cancer[1]):
    print("Cancer")
elif(date_leo[0] <= date_time_obj <= date_leo[1]):
    print("Leo")
elif(date_virgo[0] <= date_time_obj <= date_virgo[1]):
    print("Virgo")
elif(date_libra[0] <= date_time_obj <= date_libra[1]):
    print("Libra")
elif(date_scorpio[0] <= date_time_obj <= date_scorpio[1]):
    print("Scorpio")
elif(date_saggitarius[0] <= date_time_obj <= date_saggitarius[1]):
    print("Sagittarius")
elif(date_aquarius[0] <= date_time_obj <= date_aquarius[1]):
    print("Aquarius")
elif(date_pisces[0] <= date_time_obj <= date_pisces[1]):
    print("Pisces")
else:
    print("Capricorn")
