# assumption: flying incurs no cost

def fly_time(of1, of2):
    pass # return int

def get_holidays(of, week):
    pass # returns int

# assume global var integer 'num_offices' equal to number of offices
num_offices = 10

# dp contains, number of max holidays you can have if you are at a given office
# just before the given week, and can start travel immediately.
dp = [[-1] * 52] * num_offices

def max_holidays():
    for off in range(num_offices):
        dp[off][51] = get_holidays(off, 51)
    for week_num in range(50, -1, -1):
        for off in range(10):
            curr_hol = get_holidays(off, week_num)
            can_fly = [fly_time(off, i) <= 8 for i in range(num_offices)]
            next_week_hols = [dp[i, week_num+1] for i in range(num_offices)]
            max_next_week_hols = -1
            for cf, h in zip(can_fly, next_week_hols):
                if cf and max_next_week_hols < h:
                    max_next_week_hols = h
            dp[off][week_num] = curr_hol + max_next_week_hols

    return max([dp[i][0] for i in range(num_offices)])
