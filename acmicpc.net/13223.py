a,b=[input(),input()]
c=int(a[0:2])*3600+int(a[3:5])*60+int(a[6:8])
d=int(b[0:2])*3600+int(b[3:5])*60+int(b[6:8])
e=d-c
if e<=0:
	e+=86400
print(f"{'{0:02d}'.format(e//3600)}:{'{0:02d}'.format(e%3600//60)}:{'{0:02d}'.format(e%60)}")