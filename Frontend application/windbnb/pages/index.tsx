import type { NextPage } from 'next'
import Head from 'next/head'
import Image from 'next/image'
import Footer from '../component/Footer'
import Map from '../component/Map'
import Navbar from '../component/Navbar'
import Photocards from '../component/Photocards'
import styles from '../styles/Home.module.css'

const Home: NextPage = () => {
  return (
    <>
    <Navbar/>
    <Photocards/>
    <Map/>
    <Footer/>
    </>
  )
}

export default Home
