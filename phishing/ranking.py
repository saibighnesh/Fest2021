from urllib.parse import urlparse
from bs4 import BeautifulSoup
import urllib.request
import re
import requests
import csv
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier

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
        index=-1
        return index        



def get_rank(domain_to_query):

    url = "http://www.alexa.com/siteinfo/" + domain_to_query
    try:
        page = requests.get(url,verify=False).text
        soup = BeautifulSoup(page)    
        if soup.find('p',class_='big data'):
            result= soup.find('p',class_='big data').text 
            return result    
        else:
            result="# -1"
            return result
    
    except:
        print('error found')

f = open("input_url.txt", "r")
url = f.read()
r=get_rank(url)
rr=r.replace("#", "")
rank=rr.strip()
print('Rank ',rank)

index=get_index(url)
print('index',index)

