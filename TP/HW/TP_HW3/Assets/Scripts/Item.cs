using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    public float Speed;

    private float z_Pos;

    // Start is called before the first frame update
    void Start()
    {
        z_Pos = 0.0f;
    }

    // Update is called once per frame
    void Update()
    {
        z_Pos -= 0.2f;
        transform.Translate(0.0f, 0.0f, z_Pos * Speed * Time.deltaTime);

        if (transform.position.z < -10.0f)
            Destroy(gameObject, 0);
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Player")
        {
            Destroy(gameObject, 0);
        }
    }
}
