from urllib.parse import urlparse
from bs4 import BeautifulSoup
import urllib.request
import re
import requests
import csv
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier

def get_domains(url):

    data = urlparse(url)
    domain = data.netloc
    #print(domain)
    path = data.path
    #print(path)
    subdomain=urlparse(url).hostname.split('.')
    #print(subdomain)
    if len(subdomain) > 3:
        sdflag=1
    else:
        sdflag=0
    if(domain==''):
        path,domain,subdomain=-1,-1,-1
        return path,domain,subdomain
    elif(path=='' and sdflag==0):
        path,domain,subdomain=-1,1,-1
        return path,domain,subdomain
    elif(path==''):
        path,domain,subdomain=-1,1,1
        return path,domain,subdomain
    else:
        path,domain,subdomain=1,1,1
        return path,domain,subdomain


def get_index(url):
    hdr = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.64 Safari/537.11',
       'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
       'Accept-Charset': 'ISO-8859-1,utf-8;q=0.7,*;q=0.3',
       'Accept-Encoding': 'none',
       'Accept-Language': 'en-US,en;q=0.8',
       'Connection': 'keep-alive'}
    try:   
        req = urllib.request.Request("https://www.google.com/search?q="+url,headers=hdr)
        html_page=urllib.request.urlopen(req)
        soup = BeautifulSoup(html_page,features="lxml")
        if("did not match any documents." in str(soup)):
            index=-1
            return index
        else:
            index=1
            return index
    except:
        #index=-1
        #return index
        print('error')		



def get_rank(domain_to_query):

    url = "https://www.rankranger.com/top-websites?domain=" + domain_to_query
    try:
        page = requests.get(url,verify=False).text
        soup = BeautifulSoup(page) 
        #print(soup)
        table = soup.find('td',class_='grid_td tc')	
        if soup.find('td',class_='grid_td tc'):
            result= soup.find('td',class_='grid_td tc')	.text 
            return result 
           
        else:
            result="-1"
            return result
    except:
        print('error found')


fin = open("input_url.txt","r")
url = fin.read()
fin.close()
#print(url)

r=get_rank(url)
#print('Rank ',r)
path,domain,subdomain=get_domains(url)
#print('path,domain,sub',path,domain,subdomain)
index=get_index(url)
#print('index',index)

rank = int(r)
inp=[url,path,subdomain,domain,rank,index]
#print(inp)

head=["Urls","Path","SubDomain","Domain","Rank","Index"]
f=open('test.csv','w')
csv_writer = csv.writer(f)
csv_writer.writerow(head)
csv_writer.writerow(inp)
f.close()

traindata = pd.read_csv("train.csv")
testdata = pd.read_csv("test.csv")

X = traindata.loc[:, ['Path', 'SubDomain', 'Domain', 'Rank', 'Index']] 
y = traindata['Result']
test = testdata.drop("Urls", axis=1)
  
scaler = StandardScaler()  
scaler.fit(X)

X = scaler.transform(X)  
test = scaler.transform(test) 
 
rf_clf = RandomForestClassifier(n_estimators = 10, criterion = 'entropy', random_state = 42)

rf_clf.fit(X, y)

y_pred = rf_clf.predict(test) 
#print(y_pred)
if y_pred[0] == 1:
    print("non phishing site")
else:
    print("phishing site")
    with open('blacklist.csv','a') as fd:
        fd.write(str(testdata['Urls'][0])+'\n')
