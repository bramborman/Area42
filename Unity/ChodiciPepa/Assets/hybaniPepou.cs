using UnityEngine;

public class hybaniPepou : MonoBehaviour {
    public int jakRychleBudePepaChodit;
    public int jakRychleBudePepaSkakat;

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	    if(Input.GetKey(KeyCode.UpArrow))
        {
            transform.Translate(Vector3.up * jakRychleBudePepaSkakat * Time.deltaTime);
        }
        else if (Input.GetKey(KeyCode.LeftArrow))
        {
            transform.Translate(Vector3.left * jakRychleBudePepaChodit * Time.deltaTime);
        }
        else if (Input.GetKey(KeyCode.RightArrow))
        {
            transform.Translate(Vector3.right * jakRychleBudePepaChodit * Time.deltaTime);
        }
    }
}
