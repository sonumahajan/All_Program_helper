
import React from 'react'

function OptionsCard(props:{title:string , number:string }) {
  return (
    <div className='flex flex-col items-center space-y-2 w-20 lg:w-18 cursor-pointer'>
        <img src={`/options/${props.number}.jpg`} width="25px" alt="" />
        <div className=' text-xs font-semibold'>{props.title}</div>
    </div>
  )
}

export default OptionsCard