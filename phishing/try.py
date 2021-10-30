from urllib.parse import urlparse
from bs4 import BeautifulSoup
import urllib.request
import re
import requests

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
		
url = 'gooogle.com'

print(get_rank(url))