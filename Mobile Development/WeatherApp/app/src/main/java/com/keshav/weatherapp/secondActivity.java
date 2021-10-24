package com.keshav.weatherapp;

import androidx.annotation.StringDef;
import androidx.appcompat.app.AppCompatActivity;

import android.app.Dialog;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.keshav.weatherapp.Custom.CustomDialog;
import com.keshav.weatherapp.Custom.OnCitySelected;
import com.keshav.weatherapp.schema.Data;

public class secondActivity extends AppCompatActivity {

    ImageView image;
    TextView temp, tempunit, city, weather, humidity, pressure;
    Dialog dialog;

    String[] cities={
            "AGARTALA","AGRA","AHMEDABAD","AJMER","ALLAHABAD","ALLEPPEY","ALMORA","ALWAR","AMBALA","AMLA",
            "AMRAVATI","AMRITSAR","ANAND","ANKLESHWAR","AULI","AURANGABAD",
            "BADDI","BADRINATH","BALRAMPUR","BANDIPUR","BANGALORE","BARBIL",
            "BAREILLY","BEHROR","BELGAUM","BETALGHAT","BHARATPUR","BHARUCH","BHAVNAGAR",
            "BHILAI","BHIMTAL","BHOPAL","BHUBANESHWAR","BHUJ","BIKANER","BINSAR","BODHGAYA","BUNDI","CALICUT","CHAIL","CHAMBA",
            "CHANDIGARH","CHENNAI","CHIKMAGALUR","CHIPLUN","COIMBATORE","COONOOR","CUTTACK",
            "Dehradun","Dispur",
            "Gandhinagar","Gangtok",
            "Imphal","Itanagar",
            "Jaipur",
            "Kohima","Kolkata",
            "Lucknow",
            "Mumbai",
            "Panaji","Patna",
            "Raipur","Ranchi",
            "Shillong","Shimla","Srinagar",
            "Thiruvananthapuram"
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        fetchdata("Panchkula");

        image=findViewById(R.id.weatherImage);
        temp=findViewById(R.id.temp);
        tempunit=findViewById(R.id.tempunit);
        weather=findViewById(R.id.wea);
        humidity=findViewById(R.id.hum);
        pressure=findViewById(R.id.press);
        city = findViewById(R.id.city);

        dialog = new CustomDialog(this, R.layout.dialog, cities, new OnCitySelected() {
            @Override
            public void OnSelected(int pos) {
                fetchdata(cities[pos]);
                dialog.dismiss();
            }
        });


        city.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                dialog.show();
            }
        });

    }

    public void fetchdata(String citys) {

        String URL = "http://api.openweathermap.org/data/2.5/weather?q="+citys+",in&APPID=c7cd1899e17cb3474d1c868b26a074d0";

        final Gson gson = new GsonBuilder().create();

        //Response From given above URL
        StringRequest request = new StringRequest(URL, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {

                Data d = gson.fromJson(response, Data.class);

                temp.setText("" + (int) (d.getMain().getTemp() - 273));
                humidity.setText("" + (d.getMain().getHumidity()));

                String we = d.getWeather().get(0).getMain();
                weather.setText(we);

                city.setText("" + d.getName());
                pressure.setText("" + (d.getMain().getPressure()) + " P");

                //setting images
                String icon = d.getWeather().get(0).getIcon();
                int res = getResources().getIdentifier("i" + icon, "drawable", "com.keshav.weatherapp");
                image.setImageResource(res);

            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {

            }
        }
        );

        RequestQueue queue= Volley.newRequestQueue(this);
        queue.add(request);
    }

}
