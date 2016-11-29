using UnityEngine;
using UnityEngine.UI;

public class PlayerController : MonoBehaviour
{
    private bool won;
    private bool isHandheld;
    private int pickUpCount;
    private Vector3 startingPosition;
    private Vector3 velocity;
    private new Rigidbody rigidbody;

    public int maxPickUpCount;
    public float speedMultiplier;
    public Text pickUpCountText;
    public GameObject winText;

    private void Start()
    {
        won = false;
        isHandheld = SystemInfo.deviceType == DeviceType.Handheld;
        startingPosition = transform.position;
        rigidbody  = GetComponent<Rigidbody>();

        pickUpCount = 0;
        pickUpCountText.text = string.Format("Count: {0}", pickUpCount);
    }

    private void Update()
    {
        if (won)
        {
            transform.position = Vector3.SmoothDamp(transform.position, startingPosition, ref velocity, 0.5f);
        }
    }

    private void FixedUpdate()
    {
        if (!won)
        {
            Vector3 movement;

            if (!isHandheld)
            {
                movement = new Vector3(Input.GetAxis("Horizontal"), 0.0f, Input.GetAxis("Vertical"));
            }
            else
            {
                movement = new Vector3(Input.acceleration.x, 0.0f, Input.acceleration.y);
            }

            rigidbody.AddForce(movement * speedMultiplier);
        }
        else
        {
            rigidbody.velocity = Vector3.zero;
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.CompareTag("PickUp"))
        {
            other.gameObject.SetActive(false);

            transform.localScale *= 1.01f;

            pickUpCountText.text = string.Format("Count: {0}", ++pickUpCount);

            if (pickUpCount == maxPickUpCount)
            {
                won = true;
                winText.SetActive(true);
            }
        }
    }
}
