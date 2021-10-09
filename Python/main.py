import requests
from twilio.rest import Client

weather_endpoint = "https://api.openweathermap.org/data/2.5/onecall"
api_key = "53a5822caa699903d17f5611c927e976"
account_sid = "AC7b3819bd4646d70f08f93f6631755bd7"
auth_token = "569fd85392d2a4f79364806934ddc26d"

parameters = {
    "lat": 53.904541,
    "lon":27.561523,
    "exclude":"current,minutely,daily",
    "appid":api_key
}

response = requests.get(weather_endpoint, params=parameters)
response.raise_for_status()
data = response.json()
data_slice = data["hourly"][:12]

will_rain = False

for hour_data in data_slice:
    condition_code = hour_data["weather"][0]["id"]
    if int(condition_code) < 700:
        will_rain = True
        
if will_rain:
    client = Client(account_sid, auth_token)
    message = client.messages \
        .create(
            body="This message was sent with Twilio.",
            from_='+14422464823',
            to='+91 93538 45652'
        )
