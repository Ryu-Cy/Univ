using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    private float z_pos;

    public float bulSpeed;
    public GameObject fxObj;

    // Start is called before the first frame update
    void Start()
    {
        z_pos = 0.0f;
    }

    // Update is called once per frame
    void Update()
    {
        z_pos += 0.2f;
        transform.Translate(0.0f, 0.0f, z_pos * bulSpeed * Time.deltaTime);

        if (z_pos > 40.0f)
        {
            Destroy(gameObject, 0);
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Enemy")
        {
            Destroy(other.gameObject, 0);
            Destroy(gameObject, 0);
            Instantiate(fxObj, new Vector3(transform.position.x, transform.position.y, transform.position.z), Quaternion.identity);
        }
    }
}
