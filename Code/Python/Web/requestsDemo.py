import requests
import csv

#Let's request the tall buildings information
response = requests.get("https://data.sfgov.org/resource/5kya-mfst.json")

#Let's check the response is OK (return code 200)
if(0 & response.status_code == 200):
    #We will convert the response to json 
    tallBuildings = response.json()
    
    #we will read the first building in the response and print some information
    building = tallBuildings[0]
    print("\tBuilding Name", building["name"])
    print("\tOccupancy: ", building["occupancy"])
    print("\tAddress: ", building["address"])

#Excercise 1: Print to the screen the list of buildings 
#including relevant information about the building like structure type
#occupancy, number of stories, , total area.
if(response.status_code == 200):
    #We will convert the response to json 
    tallBuildings = response.json()
    
    #we will read the first building in the response and print some information
    for building in tallBuildings:
        #building = tallBuildings[0]
        if "name" in building:
            print("\n\tBuilding Name: ", building["name"], end =" // ")
        if "stories_above_grade" in building:
            print("Stories: ", building["stories_above_grade"], end =" // ")
        if "structural_material" in building:
            print("Material: ", building["structural_material"], end =" // ")
        if "structural_system" in building:
            print("Structural System: ", building["structural_system"], end ="")

#Excercise 2: Write the data from excercise 1 into a csv text file including latitude and longitude
with open('buildings_locations.csv', mode='w') as buildings_file:
    buildings_writer = csv.writer(buildings_file, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
    
    buildings_writer.writerow(['Building Name', 'Latitude', 'Longitude', 'PGA'])
    for building in tallBuildings:

        polygons = building["polygon"]
        coords = polygons["coordinates"]
        points = coords[0]
        point1 = points[0]
        responsePGA = requests.get("https://earthquake.usgs.gov/nshmp-haz-ws/hazard/E2008/WUS/"+ str(point1[0]) + "/" + str(point1[1]) + "/PGA/760")
        if(responsePGA.status_code == 200):
            PGA = responsePGA.json()
            responsePGA = PGA["response"]
            PGA_0 = responsePGA[0]
            metadataPGA = PGA_0["metadata"]
            xvaluesPGA = metadataPGA["xvalues"]
            buildings_writer.writerow([building["name"], point1[0], point1[1], xvaluesPGA[0]]) #response -> 0 -> metadata -> xvalues
        else:
            buildings_writer.writerow([building["name"], point1[0], point1[1], "UNKNOWN"]) #response -> 0 -> metadata -> xvalues

print("Done!")

#Exercise 3: Can we get PGA from USGS API for each building and include it in the output file