package com.example.myapplication

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Base64
import android.util.Log
import android.view.View
import android.widget.Button
import com.example.myapplication.databinding.ActivityMainBinding
import java.util.*
import kotlin.experimental.xor

private lateinit var binding: ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private var usernames = mutableListOf<String>()
    var temp_usernames = mutableListOf<String>()
    var error2 = ""
    var error1 = ""
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)


        val loginButton = binding.btnLogin

        loginButton.setOnClickListener(){
            testLogin()
            binding.lblError.text = error1
        }

        val createUserButton = binding.btnCreateUser
        createUserButton.setOnClickListener(){
            testCreateUser()
            binding.lblError2.text = error2
            binding.lblError2.visibility = View.VISIBLE
        }
    }

    private fun testCreateUser() {
        Thread{
            val username = binding.txtUsername2.text.toString()
            if (username == "") {
                error2 = getString(R.string.errorNullLoginUsername)
            }
            else if(!usernames.contains(username)){
                temp_usernames.add(username)
                Thread.sleep(2)
                error2 = if(username == getString(R.string.Alice)) {
                    temp_usernames.remove(getString(R.string.Alice))
                    getString(R.string.errorCanNotCreateAlice)
                } else {
                    getString(R.string.createUserSuccess)
                }
            } else {
                error2 = getString(R.string.errorUsernameExist)
            }

            if(temp_usernames.size > 0){
                usernames.add(temp_usernames[0])
                temp_usernames = mutableListOf<String>()
            }
        }.start()

    }

    private fun testLogin() {
        val username = binding.txtUsername.text.toString()
        if(username != ""){
           if(usernames.contains(username)){
               if(username == "Alice") {
                   val reGetUsername = binding.txtUsername.text.toString()
                   printFlag(reGetUsername)
               } else {
                   error1 = getString(R.string.errorWaitingForAlice)
                   binding.lblError.visibility = View.VISIBLE
               }
           } else {
               error1 = getString(R.string.errorUsernameNotExist)
               binding.lblError.visibility = View.VISIBLE
           }
        } else {
            error1 = getString(R.string.errorNullLoginUsername)
            binding.lblError.visibility = View.VISIBLE
        }
    }


    private fun printFlag(username : String) {
        val reGetUsername = usernames[0]

        if(username == getString(R.string.Alice) && username == reGetUsername){
            val encrypt = Base64.decode(getString(R.string.flag), Base64.DEFAULT)
            val usernameByte = username.toByteArray(Charsets.UTF_8)
            var i = 0
            var result = byteArrayOf()
            for(b in encrypt){
                result += b.xor(usernameByte[i])
                i++
                if(i == usernameByte.size){
                    i = 0
                }
            }
            val strResult = String(result)
            error1 = strResult
            binding.lblError.visibility = View.VISIBLE
        }
    }


}