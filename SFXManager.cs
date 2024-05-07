using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SFXManager : MonoBehaviour
{

   
    [SerializeField] private ParticleSystem playerExplosion;
    ParticleSystem finishConfetti;
    [SerializeField] private ParticleSystem playerRocketBoost;
    [SerializeField] private ParticleSystem playerLeftAuxRocketBoost;
    [SerializeField] private ParticleSystem playerRightAuxRocketBoost;
    void Awake()
    {
        
        //finish confetti for finish landing pad
    }

    
    void Update()
    {
        
    }

    public void ExplosionSFX()
    {
        playerExplosion.Play();
    }

    public void MainEngineBoostActiveSFX()
    {
        playerRocketBoost.Play();
    }

    public void MainEngineBoostStopSFX()
    {
        playerRocketBoost.Stop();
    }

    public void AuxiliaryEngineBoostLeftStartSFX() 
    {
            playerLeftAuxRocketBoost.Play();
    }

    public void AuxiliaryEngineBoosLeftStopSFX()
    {
        playerLeftAuxRocketBoost.Stop();
        
    }

    public void AuxiliaryEngineBoostRightStartSFX()
    {
        
         
            playerRightAuxRocketBoost.Play();

     
    }

    public void AuxiliaryEngineBoostRightStopSFX()
    {
        playerRightAuxRocketBoost.Stop();
    }
}
