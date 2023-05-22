dict = { "안녕" : "hello" }
print(dict)

if "안녕" in dict:
    print("yes")

if "d" not in dict:
    print("no")

dict["hello"] = "안녕"
print(dict)