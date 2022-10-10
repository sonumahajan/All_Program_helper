import type { NextPage } from 'next'
import Link from 'next/link'

const Home: NextPage = (props:any) => {
  return (  
    <div>
      <h1 className=' text-4xl text-center pt-16 lg:pt-20 mx-4 font-bold text-white myfont'>Welcome to Random Text Generator🪄🥳</h1>
      <div className='mb-10 mt-16 mx-10 lg:mx-20 border-2 bg-blue-400 p-6 shadow-2xl'>
        {props.heading && <h1 className='text-3xl text-center font-bold mb-10 myfont'>{props.heading}</h1>}
        {props.details && <p className='text-2xl text-center font-semibold myfont'>{props.details}</p>}
      </div>
      <div className='flex justify-center items-center mb-32' >
      <Link href='/'><button className='myfont text-white border-2 duration-200 hover:bg-red-600 p-4 flex shadow-2xl items-center rounded-xl bg-red-800' >Generate🥰</button></Link>
      </div>
        <div className='fixed bottom-0 w-full text-center bg-blue-500 h-16 lg:h-14 footer'>
          <div className='flex justify-center mt-3 lg:mt-2 text-white footer myfont items-center text-2xl font-bold px-2'>Made with 🪄  by Divyanshu</div>
        </div>
    </div>
  )
}

export default Home

export async function getServerSideProps() {
  const res = await fetch('https://jsonplaceholder.typicode.com/posts')
  const posts = await res.json()
  const post = (posts[Math.floor(Math.random() * 100) + 1])
  return {
    props: {
      heading:post.title,
      details:post.body
    },
  }
}
