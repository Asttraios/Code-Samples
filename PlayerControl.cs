using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerControl : MonoBehaviour
{
    [SerializeField] private float normalSpeed;
    [SerializeField] private float sprintSpeed;
    [SerializeField] private float maxSpeed;
    private Vector3 move;
    Rigidbody rb;

    void Start()
    {
        rb = GetComponent<Rigidbody>();
    }

    private void Update()
    {
        //Debug.Log(rb.velocity);

    }

    // Update is called once per frame
    void FixedUpdate()
    {
        move.x = Input.GetAxis("Horizontal")  * normalSpeed;
        move.z = Input.GetAxis("Vertical") * normalSpeed;
        
        //transform.Translate(move.x, 0, move.z, Space.World);

        rb.AddForce(move.x, 0, move.z, ForceMode.VelocityChange);

        rb.velocity = Vector3.ClampMagnitude(rb.velocity, maxSpeed);
    }
}
