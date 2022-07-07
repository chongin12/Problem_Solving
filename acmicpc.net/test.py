import json

file_path = "./Package.resolved"

with open(file_path, 'r') as file:
    data = json.load(file)
    print("[")
    for i in data["pins"]:
        identity=i["identity"].capitalize()
        location=i["location"].replace(".git", "")
        ver=i["state"]["version"]
        print(f'    OpenSource(name: "{identity}", url: "{location}", description: nil, version: "{ver}"),')
    print("]")