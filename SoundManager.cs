using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SoundManager : MonoBehaviour
{
    [SerializeField] private AudioClip[] soundSFX;
    [SerializeField] private AudioClip onFireSFX;
    [SerializeField] private AudioClip playerWin;
    [SerializeField] private AudioClip AuxEngineSFX;
    
    [SerializeField] private AudioSource[] playerAudioArray;
    private AudioSource playerAudioOne;
     private AudioSource playerAudioTwo;
    private bool ifPlayed;
    
    void Start()
    {
        playerAudioArray = GameObject.FindGameObjectWithTag("Player").GetComponents<AudioSource>();
        playerAudioOne = playerAudioArray[0];
        playerAudioTwo = playerAudioArray[1];

        ifPlayed = false;
    }

    public void PlayerExplosionSounds()
    {   
        if(!ifPlayed)
        {
        playerAudioOne.Stop();
        }
        

        if (playerAudioOne.isPlaying == false)
        {
        playerAudioOne.clip = soundSFX[Random.Range(0, soundSFX.Length)];
        playerAudioOne.PlayOneShot(playerAudioOne.clip);
        playerAudioOne.PlayOneShot(onFireSFX);
        ifPlayed = true;
        }
        
    }

    public void PlayerFinishLevel()
    {
        playerAudioOne.clip = playerWin;
        playerAudioOne.PlayOneShot(playerAudioOne.clip);
        ifPlayed = true;
    }

    public void AuxEngineSoundPlay()
    {
  
            playerAudioTwo.Play();
 
    }

    public void AuxEngineSoundStop() {
    
        playerAudioTwo.Stop();
    
    }
}
