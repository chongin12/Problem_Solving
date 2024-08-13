import datetime
a,b=map(int,input().split())
dt = datetime.datetime(2009, b, a).weekday()
d = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
print(d[dt])