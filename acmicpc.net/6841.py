while True:
    try:
        a=input()
        k=a
        if a=="CU":k="see you"
        if a==":-)":k="I’m happy"
        if a==":-(":k="I’m unhappy"
        if a==";-)":k="wink"
        if a==":-P":k="stick out my tongue"
        if a=="(~.~)":k="sleepy"
        if a=="TA":k="totally awesome"
        if a=="CCC":k="Canadian Computing Competition"
        if a=="CUZ":k="because"
        if a=="TY":k="thank-you"
        if a=="YW":k="you’re welcome"
        if a=="TTYL":k="talk to you later"
        print(k)
    except:
        break